#include "PatientAdmissionClerk.h"
#include "InputUtils.h"
#include <iostream>

using std::cout;

void PatientAdmissionClerk::admitPatient()
{
    Patient p;
    p.id = readInt("Enter Patient ID: ");
    p.name = readLine("Enter Patient Name: ");
    p.conditionType = readLine("Enter Condition Type: ");

    q.push(p);
    cout << ">> Patient admitted to queue.\n";
}

void PatientAdmissionClerk::dischargePatient()
{
    if (q.empty())
    {
        cout << ">> No patients to discharge.\n";
        return;
    }
    Patient p = q.front();
    q.pop();
    cout << ">> Discharged Patient [ID: " << p.id << ", Name: " << p.name << "]\n";
}

void PatientAdmissionClerk::viewQueue() const
{
    if (q.empty())
    {
        cout << ">> Patient queue is empty.\n";
        return;
    }
    std::queue<Patient> copy = q;
    cout << "\n-- Patient Queue (front -> back) --\n";
    int pos = 1;
    while (!copy.empty())
    {
        const Patient& p = copy.front();
        cout << pos++ << ". ID: " << p.id
             << " | Name: " << p.name
             << " | Condition: " << p.conditionType << '\n';
        copy.pop();
    }
}
