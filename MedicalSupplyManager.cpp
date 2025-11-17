#include "MedicalSupplyManager.h"
#include "InputUtils.h"
#include <iostream>

using std::cout;

void MedicalSupplyManager::addSupply()
{
    Supply s;
    s.type = readLine("Enter Supply Type: ");
    s.quantity = readInt("Enter Quantity: ");
    s.batch = readLine("Enter Batch: ");

    st.push(s);
    cout << ">> Supply added (on top of stack).\n";
}

void MedicalSupplyManager::useLastAdded()
{
    if (st.empty())
    {
        cout << ">> No supplies available.\n";
        return;
    }
    Supply s = st.top();
    st.pop();
    cout << ">> Used Supply [Type: " << s.type
         << ", Qty: " << s.quantity
         << ", Batch: " << s.batch << "]\n";
}

void MedicalSupplyManager::viewSupplies() const
{
    if (st.empty())
    {
        cout << ">> No supplies in storage.\n";
        return;
    }
    std::stack<Supply> copy = st;
    cout << "\n-- Current Supplies (top -> bottom) --\n";
    int pos = 1;
    while (!copy.empty())
    {
        const Supply& s = copy.top();
        cout << pos++ << ". Type: " << s.type
             << " | Qty: " << s.quantity
             << " | Batch: " << s.batch << '\n';
        copy.pop();
    }
}
