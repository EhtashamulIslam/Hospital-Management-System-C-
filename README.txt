Hospital Patient Care Management System (C++) - Fixed Ambulance Rotation

Windows:
  1) Double-click run.bat (or build.bat then hospital.exe)
  2) Follow on-screen menus

Build with MinGW g++:
  g++ -std=c++17 -O2 -Wall -Wextra -pedantic ^
    main.cpp PatientAdmissionClerk.cpp MedicalSupplyManager.cpp EmergencyDepartmentOfficer.cpp AmbulanceDispatcher.cpp ^
    -o hospital.exe

Fix in v4:
  - Corrected ambulance rotation display after shift
  - Updated circular queue logic for displaying full schedule
