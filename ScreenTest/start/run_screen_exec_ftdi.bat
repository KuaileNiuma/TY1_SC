@echo off
rem ============================================================
rem  screen_exec automated test - FTDI adapter
rem  runs screen_test/screen_exec_ftdi.py (openocd_1core_sram.cfg)
rem ============================================================

rem switch to this script's directory for relative path resolution
cd /d "%~dp0"

python screen_test\screen_exec_ftdi.py --pause %*

echo.
echo Test finished. Press any key to close...
pause >nul
