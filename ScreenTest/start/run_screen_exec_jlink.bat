@echo off
rem ============================================================
rem  screen_exec automated test - J-Link / CMSIS-DAP adapter
rem  runs screen_test/screen_exec_jlink.py (openocd_1core_sram_jlink.cfg)
rem ============================================================

rem switch to this script's directory for relative path resolution
cd /d "%~dp0"

python screen_test\screen_exec_jlink.py --pause %*

echo.
echo Test finished. Press any key to close...
pause >nul
