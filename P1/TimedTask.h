#ifndef SENECA_TIMEDTASK_H
#define SENECA_TIMEDTASK_H

#include <iostream>
#include <chrono>
#include <string>
#include <iomanip>

namespace seneca {

struct Task {
    std::string name;
    std::string units;
    std::chrono::steady_clock::duration duration;
};

class TimedTask {
    static const int maxTasks = 10;
    int numRecords = 0;
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;
    Task tasks[maxTasks];

public:
    TimedTask() = default;

    void startClock();
    void stopClock();
    void addTask(const char* taskName);

    friend std::ostream& operator<<(std::ostream& os, const TimedTask& tt);
};

} // namespace seneca

#endif // SENECA_TIMEDTASK_H
