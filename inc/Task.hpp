#ifndef TASK_HPP
#define TASK_HPP

#include <functional>
#include <chrono>

namespace h72{

class Task
{
public:
    Task() = default;
    explicit Task(std::function<void()>const& a_func, std::chrono::milliseconds a_milTime);
    Task(Task const& a_task);
    Task& operator=(Task const& a_task);
    ~Task() = default;

    bool operator<(Task const& a_task) const;
    void RunTask();
    void UpdateNextTime();

private:
    std::function<void()> m_func;
    std::chrono::milliseconds m_milTime;
    std::chrono::time_point<std::chrono::steady_clock> m_nextTime;
};

}

#endif
