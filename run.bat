@echo off
if not exist hospital.exe (
  echo hospital.exe not found. Building first...
  call build.bat
  if %errorlevel% neq 0 exit /b %errorlevel%
)
echo.
echo ================== Hospital Patient Care Management System ==================
echo If the screen looks blank, it's waiting for input.
echo Type a number (e.g., 1) and press ENTER to navigate the menu.
echo.
hospital.exe
echo.
pause
