#ifndef AMBULANCE_DISPATCHER_H
#define AMBULANCE_DISPATCHER_H

#include <string>
#include <vector>

class AmbulanceCircularQueue
{
private:
    std::vector<std::string> buf;
    std::size_t head{0};  // Points to the first ambulance
    std::size_t count{0}; // Number of ambulances in queue
    std::size_t capacity;

public:
    explicit AmbulanceCircularQueue(std::size_t cap = 64)
        : buf(cap), capacity(cap) {}

    bool isFull() const { return count == capacity; }
    bool isEmpty() const { return count == 0; }

    bool enqueue(const std::string& ambId)
    {
        if (isFull()) return false;
        std::size_t tail = (head + count) % capacity;
        buf[tail] = ambId;
        count++;
        return true;
    }

    bool rotateOnce()
    {
        if (count <= 1) return false;  // No rotation needed if less than 2 ambulances
        head = (head + 1) % capacity;  // Rotate the schedule
        return true;
    }

    std::vector<std::string> snapshot() const
    {
        std::vector<std::string> out;
        out.reserve(count);
        for (std::size_t i = 0; i < count; ++i)
        {
            out.push_back(buf[(head + i) % capacity]);  // Get the ambulances in correct order
        }
        return out;
    }
};

class AmbulanceDispatcher
{
private:
    AmbulanceCircularQueue cq;

public:
    explicit AmbulanceDispatcher(std::size_t capacity = 64) : cq(capacity) {}
    void registerAmbulance();
    void rotateShift();
    void displaySchedule() const;
};

#endif // AMBULANCE_DISPATCHER_H
