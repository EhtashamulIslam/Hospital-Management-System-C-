#include <iostream>
#include "InputUtils.h"
#include "PatientAdmissionClerk.h"
#include "MedicalSupplyManager.h"
#include "EmergencyDepartmentOfficer.h"
#include "AmbulanceDispatcher.h"

using std::cout;

int menuMain()
{
    cout << "\n================= Hospital Patient Care Management System =================\n";
    cout << "1. Patient Admission Clerk (Queue)\n";
    cout << "2. Medical Supply Manager (Stack)\n";
    cout << "3. Emergency Department Officer (Priority Queue)\n";
    cout << "4. Ambulance Dispatcher (Circular Queue)\n";
    cout << "0. Exit\n";
    int c = readInt("Choose option: ");
    return c;
}

int menuPatient()
{
    cout << "\n--- Patient Admission Clerk ---\n";
    cout << "1. Admit Patient\n";
    cout << "2. Discharge Patient (earliest)\n";
    cout << "3. View Patient Queue\n";
    cout << "9. Back\n";
    int c = readInt("Choose option: ");
    return c;
}

int menuSupply()
{
    cout << "\n--- Medical Supply Manager ---\n";
    cout << "1. Add Supply Stock\n";
    cout << "2. Use 'Last Added' Supply\n";
    cout << "3. View Current Supplies\n";
    cout << "9. Back\n";
    int c = readInt("Choose option: ");
    return c;
}

int menuEmergency()
{
    cout << "\n--- Emergency Department Officer ---\n";
    cout << "1. Log Emergency Case\n";
    cout << "2. Process Most Critical Case\n";
    cout << "3. View Pending Emergency Cases\n";
    cout << "9. Back\n";
    int c = readInt("Choose option: ");
    return c;
}

int menuAmbulance()
{
    cout << "\n--- Ambulance Dispatcher ---\n";
    cout << "1. Register Ambulance\n";
    cout << "2. Rotate Ambulance Shift\n";
    cout << "3. Display Ambulance Schedule\n";
    cout << "9. Back\n";
    int c = readInt("Choose option: ");
    return c;
}

int main()
{
    PatientAdmissionClerk patientClerk;
    MedicalSupplyManager supplyManager;
    EmergencyDepartmentOfficer emergencyOfficer;
    AmbulanceDispatcher ambulanceDispatcher(64);

    for (;;)
    {
        int mainChoice = menuMain();
        if (mainChoice == 0)
        {
            std::cout << "Exiting... Goodbye!\n";
            break;
        }

        switch (mainChoice)
        {
            case 1:
            {
                for (;;)
                {
                    int c = menuPatient();
                    if (c == 9) break;
                    if (c == 1) patientClerk.admitPatient();
                    else if (c == 2) patientClerk.dischargePatient();
                    else if (c == 3) patientClerk.viewQueue();
                    else std::cout << ">> Invalid option.\n";
                }
                break;
            }
            case 2:
            {
                for (;;)
                {
                    int c = menuSupply();
                    if (c == 9) break;
                    if (c == 1) supplyManager.addSupply();
                    else if (c == 2) supplyManager.useLastAdded();
                    else if (c == 3) supplyManager.viewSupplies();
                    else std::cout << ">> Invalid option.\n";
                }
                break;
            }
            case 3:
            {
                for (;;)
                {
                    int c = menuEmergency();
                    if (c == 9) break;
                    if (c == 1) emergencyOfficer.logEmergency();
                    else if (c == 2) emergencyOfficer.processMostCritical();
                    else if (c == 3) emergencyOfficer.viewPendingCases();
                    else std::cout << ">> Invalid option.\n";
                }
                break;
            }
            case 4:
            {
                for (;;)
                {
                    int c = menuAmbulance();
                    if (c == 9) break;
                    if (c == 1) ambulanceDispatcher.registerAmbulance();
                    else if (c == 2) ambulanceDispatcher.rotateShift();
                    else if (c == 3) ambulanceDispatcher.displaySchedule();
                    else std::cout << ">> Invalid option.\n";
                }
                break;
            }
            default:
                std::cout << ">> Invalid option.\n";
        }
    }
    return 0;
}
