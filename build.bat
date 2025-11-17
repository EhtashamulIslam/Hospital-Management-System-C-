@echo off
where g++ >nul 2>nul
if %errorlevel% neq 0 (
  echo [ERROR] g++ not found. Install MinGW-w64 and add g++ to PATH.
  echo https://www.mingw-w64.org/
  pause
  exit /b 1
)
echo [BUILD] Compiling sources...
g++ -std=c++17 -O2 -Wall -Wextra -pedantic ^
  main.cpp PatientAdmissionClerk.cpp MedicalSupplyManager.cpp EmergencyDepartmentOfficer.cpp AmbulanceDispatcher.cpp ^
  -o hospital.exe
if %errorlevel% neq 0 (
  echo [ERROR] Build failed.
  pause
  exit /b 1
)
echo [OK] Build succeeded: hospital.exe
