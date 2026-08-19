#!/usr/bin/env python3

"""
ELF 自动化筛选测试程序。

功能：
1. 在指定目录以及它的所有子目录中递归寻找 .elf 文件。
2. 逐个启动 alb32-riscv-elf-gdb。
3. 在 GDB 中执行 source gdb_exec。
4. 执行 continue。
5. continue 超时后，向当前 GDB 会话发送真正的 Ctrl+C。
6. 执行 i r a0，读取 a0 返回值。
7. a0 == 0x5A 判定为 success；a0 == 0xA5 判定为 fail；
   其他返回值也判定为 fail。
8. 超时 case 无论中断时 a0 是多少，都判定为 fail。
9. 每个 case 完成后退出 GDB。
10. 生成汇总结果文件和每个 case 的完整 GDB 日志。

依赖：
    Python 3
    pexpect

目标运行平台：
    Linux
"""

from __future__ import annotations

import subprocess
import argparse
import os
import re
import sys
import time
import uuid
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Optional

DEFAULT_GDB_BIN = (
    r"..\..\..\.."
    r"\toolchain"
    r"\gcc"
    r"\bin"
    r"\alb32-riscv-elf-gdb.exe"
)

# GDB启动并首次显示提示符的默认超时时间。
DEFAULT_START_TIMEOUT = 30

# 执行 source gdb_exec，其中包括连接目标板和 load 的默认超时时间。
# 因为 gdb_exec 中的 set remotetimeout 是250秒，所以这里默认设置成300秒。
DEFAULT_INIT_TIMEOUT = 300

# 单个case执行continue后的默认超时时间。
DEFAULT_CASE_TIMEOUT = 300

# 发送Ctrl+C或者执行寄存器命令后，等待GDB重新出现提示符的时间。
DEFAULT_INTERRUPT_TIMEOUT = 30

# quit后等待GDB进程退出的时间。
DEFAULT_QUIT_TIMEOUT = 10
# Case返回值约定。
PASS_RETURN_VALUE = 0x5A
FAIL_RETURN_VALUE = 0xA5

# 本地OpenOCD调试服务器配置（与工程IDE调试一致）。
# 相对路径基于 screen_exec.py 所在目录（ScreenTest/start）解析。
DEFAULT_OPENOCD_BIN = (
    r"..\..\..\.."
    r"\toolchain"
    r"\openocd"
    r"\bin"
    r"\openocd.exe"
)
DEFAULT_OPENOCD_CFG = (
    r"..\.."
    r"\Utilities"
    r"\Scripts"
    r"\openocd_1core_sram_jlink.cfg"
)
DEFAULT_GDB_PORT = 3333
# 等待OpenOCD就绪（gdb端口可连接）的超时时间。
DEFAULT_OPENOCD_READY_TIMEOUT = 30


@dataclass
class TestResult:
    """一个ELF case的执行结果。"""

    success: bool
    timed_out: bool
    return_value: Optional[int]
    detail: str
    elapsed_seconds: float


def wait_for_port(
    host: str,
    port: int,
    timeout: float,
) -> bool:
    """等待指定TCP端口可以建立连接。"""
    import socket

    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        try:
            with socket.create_connection(
                (host, port),
                timeout=1,
            ):
                return True
        except OSError:
            time.sleep(0.2)
    return False


def start_openocd(
    openocd_bin: Path,
    openocd_cfg: Path,
    gdb_port: int,
    ready_timeout: float,
) -> subprocess.Popen:
    """启动本地OpenOCD调试服务器并等待gdb端口就绪。"""
    # 启动前清理可能占用gdb端口的残留OpenOCD进程，避免端口冲突。
    try:
        kill_result = subprocess.run(
            ["taskkill", "/F", "/IM", "openocd.exe"],
            capture_output=True, text=True, timeout=5,
        )
        if kill_result.returncode == 0:
            print("已关闭残留的OpenOCD进程。")
    except Exception as exc:
        print(f"清理残留OpenOCD时出错：{exc}")

    if not openocd_bin.is_file():
        raise FileNotFoundError(
            f"找不到OpenOCD程序：{openocd_bin}"
        )
    if not openocd_cfg.is_file():
        raise FileNotFoundError(
            f"找不到OpenOCD配置文件：{openocd_cfg}"
        )

    command = [
        str(openocd_bin),
        "-c",
        "set BOOT_HARTID 0;",
        "-f",
        str(openocd_cfg),
    ]
    print(
        "启动OpenOCD："
        + subprocess.list2cmdline(command)
    )

    process = subprocess.Popen(
        command,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )

    if not wait_for_port(
        "localhost",
        gdb_port,
        ready_timeout,
    ):
        process.kill()
        process.wait(timeout=5)
        raise TimeoutError(
            f"OpenOCD在{ready_timeout}秒内未就绪"
            f"（gdb端口{gdb_port}）"
        )

    print(f"OpenOCD已就绪（gdb端口 {gdb_port}）")
    return process


def positive_integer(value: str) -> int:
    """argparse使用的正整数检查函数。"""

    try:
        number = int(value)
    except ValueError as exc:
        raise argparse.ArgumentTypeError(
            f"{value!r} 不是整数"
        ) from exc

    if number <= 0:
        raise argparse.ArgumentTypeError(
            f"{value!r} 必须是大于0的整数"
        )

    return number


def gdb_quote_path(path: Path) -> str:
    """
    将路径转换成可以安全放入GDB命令中的双引号字符串。

    Linux路径一般不包含反斜杠，但这里仍然进行完整转义。
    """

    text = str(path)
    text = text.replace("\\", "\\\\")
    text = text.replace('"', '\\"')
    return f'"{text}"'


def strip_ansi(text: str) -> str:
    """去除终端输出中的ANSI颜色或控制字符。"""

    ansi_pattern = re.compile(
        r"\x1b(?:[@-Z\\-_]|\[[0-?]*[ -/]*[@-~])"
    )
    return ansi_pattern.sub("", text)


def find_first_pattern(
    text: str,
    patterns: tuple[str, ...],
) -> Optional[str]:
    """在输出中寻找第一个错误关键字。"""

    lowered = strip_ansi(text).lower()

    for pattern in patterns:
        if pattern.lower() in lowered:
            return pattern

    return None


def find_initialization_error(text: str) -> Optional[str]:
    """
    检查target remote、load等初始化输出中常见的错误。

    如果找到错误，返回错误关键字；否则返回None。
    """

    patterns = (
    "connection timed out",
    "connection refused",
    "connection reset",
    "no route to host",
    "could not connect",
    "remote communication error",
    "remote connection closed",
    "the connection is closed",
    "load failed",
    "error finishing flash operation",
    "file format not recognized",
    "not in executable format",
    "undefined command:",
    )

    return find_first_pattern(text, patterns)


def find_execution_error(text: str) -> Optional[str]:
    """
    检查continue返回后是否出现明显的执行错误。

    SIGTRAP没有放在错误列表中，因为嵌入式case常使用ebreak/SIGTRAP
    作为正常测试结束方式。
    """

    patterns = (
        "the program is not being run",
        "cannot execute this command",
        "no executable file specified",
        "remote communication error",
        "remote connection closed",
        "the connection is closed",
        "program received signal sigsegv",
        "program received signal sigbus",
        "program received signal sigill",
        "program received signal sigabrt",
        "program received signal sigfpe",
        "program received signal sigsys",
        "program terminated with signal",
    )

    return find_first_pattern(text, patterns)


def parse_a0(register_output: str) -> Optional[int]:
    """
    从GDB的“i r a0”输出中解析a0。

    常见输出形式如下：

        a0             0x0                 0

    或：

        a0             0x3                 3

    优先读取a0后面的第一个数值，一般是十六进制值。
    """

    cleaned = strip_ansi(register_output)

    match = re.search(
        r"(?mi)^\s*a0\s+(0x[0-9a-f]+|[-+]?[0-9]+)(?:\s|$)",
        cleaned,
    )

    if match is None:
        return None

    value_text = match.group(1)

    try:
        return int(value_text, 0)
    except ValueError:
        return None


def run_one_case(
    elf_file: Path,
    log_file: Path,
    gdb_bin: Path,
    gdb_command_file: Path,
    start_timeout: int,
    init_timeout: int,
    case_timeout: int,
    interrupt_timeout: int,
    quit_timeout: int,
) -> TestResult:
    """使用GDB批处理模式运行单个ELF case。"""

    begin_time = time.monotonic()

    with log_file.open(
        "w",
        encoding="utf-8",
        errors="replace",
        newline="\n",
    ) as log_handle:
        try:
            log_handle.write(
                f"ELF: {elf_file}\n"
                f"GDB: {gdb_bin}\n"
                f"GDB命令文件: {gdb_command_file}\n"
                f"case超时: {case_timeout}秒\n"
                f"开始时间: {datetime.now().astimezone().isoformat()}\n"
                f"{'=' * 78}\n"
            )
            log_handle.flush()

            # 构造GDB批处理命令文件内容（内联，避免source外部文件路径问题）。
            cmd_content = (
                "set pagination off\n"
                "set confirm off\n"
                "set verbose off\n"
                "set mem inaccessible-by-default off\n"
                "set remotetimeout 250\n"
                "set architecture riscv:rv32\n"
                f"target remote localhost:{DEFAULT_GDB_PORT}\n"
                f"file {elf_file.as_posix()}\n"
                "load\n"
                "tbreak _postmain_fini\n"
                "continue\n"
                "i r a0\n"
                "quit\n"
            )

            cmd_file = log_file.with_suffix(".gdbcmd")
            cmd_file.write_text(
                cmd_content,
                encoding="utf-8",
            )

            # 批处理模式：-batch执行完自动退出。
            gdb_command = [
                str(gdb_bin),
                "--quiet",
                "--nx",
                "-batch",
                "-x",
                str(cmd_file),
            ]

            log_handle.write(
                "GDB命令行: "
                + subprocess.list2cmdline(gdb_command)
                + "\n"
            )
            log_handle.flush()

            try:
                completed = subprocess.run(
                    gdb_command,
                    capture_output=True,
                    text=True,
                    timeout=case_timeout,
                )
            except subprocess.TimeoutExpired as exc:
                if exc.stdout is not None:
                    log_handle.write(exc.stdout)
                log_handle.write(
                    "\n[Python控制程序] continue运行超过"
                    f"{case_timeout}秒，判为超时fail。\n"
                )
                log_handle.flush()
                elapsed = time.monotonic() - begin_time
                return TestResult(
                    success=False,
                    timed_out=True,
                    return_value=None,
                    detail=(
                        f"case运行超过{case_timeout}秒；"
                        "批处理模式无法中断，判为fail"
                    ),
                    elapsed_seconds=elapsed,
                )

            output = (completed.stdout or "") + (completed.stderr or "")
            log_handle.write(output)
            log_handle.flush()

            elapsed = time.monotonic() - begin_time

            return_value = parse_a0(output)

            if return_value is None:
                return TestResult(
                    success=False,
                    timed_out=False,
                    return_value=None,
                    detail=(
                        "GDB已退出，但无法从输出解析a0；"
                        "请查看GDB日志"
                    ),
                    elapsed_seconds=elapsed,
                )

            if return_value == PASS_RETURN_VALUE:
                return TestResult(
                    success=True,
                    timed_out=False,
                    return_value=return_value,
                    detail=(
                        "case正常停止，"
                        f"a0=0x{return_value:x}，测试成功"
                    ),
                    elapsed_seconds=elapsed,
                )

            if return_value == FAIL_RETURN_VALUE:
                return TestResult(
                    success=False,
                    timed_out=False,
                    return_value=return_value,
                    detail=(
                        "case正常停止，"
                        f"a0=0x{return_value:x}，测试失败"
                    ),
                    elapsed_seconds=elapsed,
                )

            return TestResult(
                success=False,
                timed_out=False,
                return_value=return_value,
                detail=(
                    "case正常停止，但返回值不是成功值0x5a："
                    f"a0=0x{return_value:x}"
                ),
                elapsed_seconds=elapsed,
            )

        except OSError as exc:
            elapsed = time.monotonic() - begin_time
            return TestResult(
                success=False,
                timed_out=False,
                return_value=None,
                detail=f"启动或控制GDB失败：{exc}",
                elapsed_seconds=elapsed,
            )

        except Exception as exc:
            elapsed = time.monotonic() - begin_time
            return TestResult(
                success=False,
                timed_out=False,
                return_value=None,
                detail=(
                    "Python自动化程序出现未预期异常："
                    f"{type(exc).__name__}: {exc}"
                ),
                elapsed_seconds=elapsed,
            )

        finally:
            log_handle.write(
                f"{'=' * 78}\n"
                f"结束时间: "
                f"{datetime.now().astimezone().isoformat()}\n"
            )
            log_handle.flush()


def make_log_name(
    index: int,
    relative_elf: Path,
) -> str:
    """根据ELF相对路径生成安全且唯一的日志文件名。"""

    relative_text = relative_elf.as_posix()

    safe_name = re.sub(
        r"[^0-9A-Za-z_.-]+",
        "_",
        relative_text,
    ).strip("_")

    if not safe_name:
        safe_name = "unnamed_case.elf"

    return f"{index:04d}_{safe_name}.gdb.log"


def format_result_line(
    relative_elf: Path,
    result: TestResult,
) -> str:
    """生成符合要求的汇总结果行。"""

    case_name = relative_elf.as_posix()

    if result.success:
        return (
            f"{case_name}——success——"
            f"return 0x{result.return_value:x}"
        )

    if result.timed_out:
        # 超时无论中断时a0是什么，都判定为fail。
        return f"{case_name}——fail"

    if result.return_value is not None:
        return (
            f"{case_name}——fail——"
            f"return 0x{result.return_value:x}"
        )

    return f"{case_name}——fail"


def append_text(path: Path, text: str) -> None:
    """以UTF-8格式向文件追加文本。"""

    with path.open(
        "a",
        encoding="utf-8",
        newline="\n",
    ) as file_handle:
        file_handle.write(text)


def create_argument_parser(
    script_directory: Path,
) -> argparse.ArgumentParser:
    """创建命令行参数解析器。"""

    parser = argparse.ArgumentParser(
        description=(
            "递归寻找.elf文件，逐个使用GDB运行，"
            "超时发送Ctrl+C，读取a0并生成测试汇总。"
        ),
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )

    parser.add_argument(
        "case_directory",
        nargs="?",
        default=str(script_directory / "elfs"),
        help=(
            "搜索.elf文件的目录（默认脚本目录下elfs文件夹）；会递归搜索"
        ),
    )

    parser.add_argument(
        "output_file",
        nargs="?",
        default=None,
        help=(
            "测试汇总文件；不指定时在脚本目录results文件夹"
            "生成带时间戳的文件"
        ),
    )

    parser.add_argument(
        "--gdb-bin",
        default=DEFAULT_GDB_BIN,
        help="alb32-riscv-elf-gdb的完整路径",
    )

    parser.add_argument(
        "--openocd-bin",
        default=DEFAULT_OPENOCD_BIN,
        help="OpenOCD可执行文件路径；默认相对screen_exec.py解析",
    )

    parser.add_argument(
        "--openocd-cfg",
        default=DEFAULT_OPENOCD_CFG,
        help="OpenOCD配置文件路径；默认相对screen_exec.py解析",
    )

    parser.add_argument(
        "--no-openocd",
        action="store_true",
        help="不自动启动OpenOCD（需自己先启动调试服务器）",
    )

    parser.add_argument(
        "--gdb-port",
        type=positive_integer,
        default=DEFAULT_GDB_PORT,
        help="OpenOCD的gdb端口号",
    )

    parser.add_argument(
        "--gdb-command-file",
        default=str(script_directory / "gdb_exec"),
        help="执行source时使用的GDB命令文件",
    )

    parser.add_argument(
        "--start-timeout",
        type=positive_integer,
        default=DEFAULT_START_TIMEOUT,
        help="等待GDB启动提示符的秒数",
    )

    parser.add_argument(
        "--init-timeout",
        type=positive_integer,
        default=DEFAULT_INIT_TIMEOUT,
        help="等待target remote和load完成的秒数",
    )

    parser.add_argument(
        "--case-timeout",
        type=positive_integer,
        default=DEFAULT_CASE_TIMEOUT,
        help="单个case执行continue后允许运行的秒数",
    )

    parser.add_argument(
        "--interrupt-timeout",
        type=positive_integer,
        default=DEFAULT_INTERRUPT_TIMEOUT,
        help="发送Ctrl+C或读取寄存器后等待提示符的秒数",
    )

    parser.add_argument(
        "--quit-timeout",
        type=positive_integer,
        default=DEFAULT_QUIT_TIMEOUT,
        help="等待GDB正常退出的秒数",
    )

    return parser


def main() -> int:
    """程序入口。"""

    script_directory = Path(__file__).resolve().parent
    parser = create_argument_parser(script_directory)
    arguments = parser.parse_args()

    case_directory = (
        Path(arguments.case_directory)
        .expanduser()
        .resolve()
    )

    gdb_bin_raw = Path(arguments.gdb_bin).expanduser()
    gdb_bin = (
        (script_directory / gdb_bin_raw)
        if not gdb_bin_raw.is_absolute()
        else gdb_bin_raw
    ).resolve()

    gdb_command_file = (
        Path(arguments.gdb_command_file)
        .expanduser()
        .resolve()
    )

    if not case_directory.is_dir():
        print(
            f"错误：ELF搜索目录不存在：{case_directory}",
            file=sys.stderr,
        )
        return 2

    if not gdb_bin.is_file():
        print(
            f"错误：找不到GDB程序：{gdb_bin}",
            file=sys.stderr,
        )
        return 2

    if not os.access(gdb_bin, os.X_OK):
        print(
            f"错误：GDB程序没有执行权限：{gdb_bin}",
            file=sys.stderr,
        )
        return 2

    if not gdb_command_file.is_file():
        print(
            f"错误：找不到gdb_exec：{gdb_command_file}",
            file=sys.stderr,
        )
        return 2

    if not os.access(gdb_command_file, os.R_OK):
        print(
            f"错误：无法读取gdb_exec：{gdb_command_file}",
            file=sys.stderr,
        )
        return 2

    # 解析OpenOCD路径（相对路径基于脚本目录）。
    openocd_bin_raw = Path(arguments.openocd_bin).expanduser()
    openocd_bin = (
        (script_directory / openocd_bin_raw)
        if not openocd_bin_raw.is_absolute()
        else openocd_bin_raw
    ).resolve()

    openocd_cfg_raw = Path(arguments.openocd_cfg).expanduser()
    openocd_cfg = (
        (script_directory / openocd_cfg_raw)
        if not openocd_cfg_raw.is_absolute()
        else openocd_cfg_raw
    ).resolve()

    openocd_process = None
    if not arguments.no_openocd:
        try:
            openocd_process = start_openocd(
                openocd_bin=openocd_bin,
                openocd_cfg=openocd_cfg,
                gdb_port=arguments.gdb_port,
                ready_timeout=DEFAULT_OPENOCD_READY_TIMEOUT,
            )
        except (FileNotFoundError, TimeoutError, OSError) as exc:
            print(
                f"错误：启动OpenOCD失败：{exc}",
                file=sys.stderr,
            )
            return 2

    run_id = datetime.now().strftime(
        "%Y%m%d_%H%M%S_%f"
    )

    if arguments.output_file is None:
        output_file = (
            script_directory / "results"
            / f"test_result_{run_id}.txt"
        )
    else:
        output_file = (
            Path(arguments.output_file)
            .expanduser()
            .resolve()
        )

    try:
        output_file.parent.mkdir(
            parents=True,
            exist_ok=True,
        )
    except OSError as exc:
        print(
            "错误：无法创建结果文件目录："
            f"{output_file.parent}：{exc}",
            file=sys.stderr,
        )
        return 2

    log_directory = (
        script_directory / "logs"
        / f"gdb_logs_{run_id}"
    )

    try:
        log_directory.mkdir(
            parents=True,
            exist_ok=False,
        )
    except OSError as exc:
        print(
            "错误：无法创建GDB日志目录："
            f"{log_directory}：{exc}",
            file=sys.stderr,
        )
        return 2

    # 只匹配小写.elf，与需求中的文件后缀保持一致。
    # 如果还需要匹配.ELF，可以将这里改成按suffix.lower()判断。
    elf_files = sorted(
        (
            path
            for path in case_directory.rglob("*.elf")
            if path.is_file()
        ),
        key=lambda path: path.relative_to(
            case_directory
        ).as_posix(),
    )

    start_time = datetime.now().astimezone()

    header = (
        f"自动化测试开始时间："
        f"{start_time.strftime('%Y-%m-%d %H:%M:%S %z')}\n"
        f"ELF搜索目录：{case_directory}\n"
        f"GDB路径：{gdb_bin}\n"
        f"GDB命令文件：{gdb_command_file}\n"
        f"GDB启动超时：{arguments.start_timeout}秒\n"
        f"GDB连接和下载超时："
        f"{arguments.init_timeout}秒\n"
        f"单个case运行超时："
        f"{arguments.case_timeout}秒\n"
        f"Ctrl+C中断等待时间："
        f"{arguments.interrupt_timeout}秒\n"
        "\n"
        "测试结果：\n"
    )

    try:
        output_file.write_text(
            header,
            encoding="utf-8",
            newline="\n",
        )
    except OSError as exc:
        print(
            f"错误：无法写入结果文件："
            f"{output_file}：{exc}",
            file=sys.stderr,
        )
        return 2

    if not elf_files:
        end_time = datetime.now().astimezone()

        append_text(
            output_file,
            (
                "未找到任何.elf文件。\n"
                "\n"
                f"自动化测试结束时间："
                f"{end_time.strftime('%Y-%m-%d %H:%M:%S %z')}\n"
                "总计：0，成功：0，失败：0\n"
                f"详细GDB日志目录：{log_directory}\n"
            ),
        )

        print(
            "没有在以下目录中找到任何.elf文件："
            f"{case_directory}",
            file=sys.stderr,
        )
        print(f"结果文件：{output_file}")
        return 2

    success_count = 0
    fail_count = 0

    for index, elf_file in enumerate(
        elf_files,
        start=1,
    ):
        relative_elf = elf_file.relative_to(
            case_directory
        )

        log_file = (
            log_directory
            / make_log_name(index, relative_elf)
        )

        print(
            f"[{index}/{len(elf_files)}] "
            f"正在测试：{relative_elf.as_posix()}"
        )
        print(f"    GDB日志：{log_file}")

        result = run_one_case(
            elf_file=elf_file,
            log_file=log_file,
            gdb_bin=gdb_bin,
            gdb_command_file=gdb_command_file,
            start_timeout=arguments.start_timeout,
            init_timeout=arguments.init_timeout,
            case_timeout=arguments.case_timeout,
            interrupt_timeout=arguments.interrupt_timeout,
            quit_timeout=arguments.quit_timeout,
        )

        result_line = format_result_line(
            relative_elf,
            result,
        )

        append_text(
            output_file,
            result_line + "\n",
        )

        if result.success:
            success_count += 1
            print(
                "    结果：SUCCESS，"
                f"return 0x{result.return_value:x}"
            )
        else:
            fail_count += 1
            print(f"    结果：FAIL，{result.detail}")

        print(
            "    耗时："
            f"{result.elapsed_seconds:.3f}秒"
        )
        print()

    end_time = datetime.now().astimezone()

    summary = (
        "\n"
        f"自动化测试结束时间："
        f"{end_time.strftime('%Y-%m-%d %H:%M:%S %z')}\n"
        f"总计：{len(elf_files)}，"
        f"成功：{success_count}，"
        f"失败：{fail_count}\n"
        f"详细GDB日志目录：{log_directory}\n"
    )

    append_text(output_file, summary)

    print("=" * 78)
    print("自动化测试完成。")
    print(
        f"总计：{len(elf_files)}，"
        f"成功：{success_count}，"
        f"失败：{fail_count}"
    )
    print(f"结果文件：{output_file}")
    print(f"GDB日志目录：{log_directory}")

    # 关闭自动启动的OpenOCD。
    if openocd_process is not None:
        try:
            openocd_process.terminate()
            openocd_process.wait(timeout=5)
            print("OpenOCD已关闭。")
        except Exception as exc:
            print(f"关闭OpenOCD时出错：{exc}")
            try:
                openocd_process.kill()
            except Exception:
                pass

    # 退出码：
    # 0：所有case成功
    # 1：至少一个case失败
    # 2：配置、环境或参数错误
    if fail_count > 0:
        return 1

    return 0


if __name__ == "__main__":
    sys.exit(main())