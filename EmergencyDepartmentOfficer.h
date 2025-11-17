#ifndef EMERGENCY_DEPARTMENT_OFFICER_H
#define EMERGENCY_DEPARTMENT_OFFICER_H

#include <string>
#include <queue>

struct EmergencyCase
{
    std::string patientName;
    std::string emergencyType;
    int priority{}; // higher = more critical

    bool operator<(const EmergencyCase& other) const
    {
        return priority < other.priority; // for max-heap
    }
};

class EmergencyDepartmentOfficer
{
private:
    std::priority_queue<EmergencyCase> pq;

public:
    void logEmergency();
    void processMostCritical();
    void viewPendingCases() const;
};

#endif // EMERGENCY_DEPARTMENT_OFFICER_H
