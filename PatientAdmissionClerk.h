#ifndef PATIENT_ADMISSION_CLERK_H
#define PATIENT_ADMISSION_CLERK_H

#include <string>
#include <queue>

struct Patient
{
    int id{};
    std::string name;
    std::string conditionType;
};

class PatientAdmissionClerk
{
private:
    std::queue<Patient> q;

public:
    void admitPatient();
    void dischargePatient();
    void viewQueue() const;
};

#endif // PATIENT_ADMISSION_CLERK_H
