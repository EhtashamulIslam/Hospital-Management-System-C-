#include "AmbulanceDispatcher.h"
#include "InputUtils.h"
#include <iostream>

using std::cout;

void AmbulanceDispatcher::registerAmbulance()
{
    std::string id = readLine("Enter Ambulance ID (e.g., AMB-101): ");
    if (!cq.enqueue(id))
    {
        cout << ">> Schedule is full. Cannot register more ambulances.\n";
    }
    else
    {
        cout << ">> Ambulance registered to active-duty list.\n";
    }
}

void AmbulanceDispatcher::rotateShift()
{
    if (!cq.rotateOnce())
    {
        cout << ">> Not enough ambulances to rotate (need at least 2).\n";
    }
    else
    {
        cout << ">> Ambulance schedule rotated.\n";
    }
}

void AmbulanceDispatcher::displaySchedule() const
{
    auto list = cq.snapshot();  // Retrieve the updated schedule
    if (list.empty())
    {
        std::cout << ">> No ambulances in the schedule.\n";
        return;
    }
    std::cout << "\n-- Ambulance Rotation (current -> next) --\n";
    for (std::size_t i = 0; i < list.size(); ++i)
    {
        std::cout << (i + 1) << ". " << list[i] << '\n';  // Display each ambulance in the updated order
    }
}
