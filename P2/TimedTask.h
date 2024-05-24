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

    void startClock() {
        startTime = std::chrono::steady_clock::now();
    }

    void stopClock() {
        endTime = std::chrono::steady_clock::now();
    }

    void addTask(const char* taskName) {
        if (numRecords < maxTasks) {
            tasks[numRecords].name = taskName;
            tasks[numRecords].units = "nanoseconds";
            tasks[numRecords].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
            ++numRecords;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const TimedTask& tt) {
        os << "--------------------------\n";
        os << "Execution Times:\n";
        os << "--------------------------\n";
        for (int i = 0; i < tt.numRecords; ++i) {
            os << std::left << std::setw(21) << tt.tasks[i].name
               << std::right << std::setw(13) << tt.tasks[i].duration.count() << " "
               << tt.tasks[i].units << "\n";
        }
        os << "--------------------------\n";
        return os;
    }
};

} // namespace seneca

#endif // SENECA_TIMEDTASK_H
