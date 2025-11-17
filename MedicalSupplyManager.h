#ifndef MEDICAL_SUPPLY_MANAGER_H
#define MEDICAL_SUPPLY_MANAGER_H

#include <string>
#include <stack>

struct Supply
{
    std::string type;
    int quantity{};
    std::string batch;
};

class MedicalSupplyManager
{
private:
    std::stack<Supply> st;

public:
    void addSupply();
    void useLastAdded();
    void viewSupplies() const;
};

#endif // MEDICAL_SUPPLY_MANAGER_H
