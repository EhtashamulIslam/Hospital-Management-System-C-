#include "EmergencyDepartmentOfficer.h"
#include "InputUtils.h"
#include <iostream>

using std::cout;

void EmergencyDepartmentOfficer::logEmergency()
{
    EmergencyCase ec;
    ec.patientName = readLine("Enter Patient Name: ");
    ec.emergencyType = readLine("Enter Type of Emergency: ");
    ec.priority = readInt("Enter Priority (higher = more critical): ");

    pq.push(ec);
    cout << ">> Emergency case logged.\n";
}

void EmergencyDepartmentOfficer::processMostCritical()
{
    if (pq.empty())
    {
        cout << ">> No emergency cases pending.\n";
        return;
    }
    EmergencyCase ec = pq.top();
    pq.pop();
    cout << ">> Processing MOST CRITICAL case:\n"
         << "   Patient: " << ec.patientName
         << " | Emergency: " << ec.emergencyType
         << " | Priority: " << ec.priority << '\n';
}

void EmergencyDepartmentOfficer::viewPendingCases() const
{
    if (pq.empty())
    {
        cout << ">> No emergency cases pending.\n";
        return;
    }
    std::priority_queue<EmergencyCase> copy = pq;
    cout << "\n-- Pending Emergency Cases (highest priority first) --\n";
    int pos = 1;
    while (!copy.empty())
    {
        const EmergencyCase& ec = copy.top();
        cout << pos++ << ". Patient: " << ec.patientName
             << " | Type: " << ec.emergencyType
             << " | Priority: " << ec.priority << '\n';
        copy.pop();
    }
}
