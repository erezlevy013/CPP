#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include <thread>
#include "SafePriorityQueue.hpp"
#include "Task.hpp"

namespace h72{

class Executor
{
public:
    Executor();
    ~Executor();

    void Add(Task const& a_task);
    void Add(Task&& a_task);
    void Run();
    void Shutdown();
    void Pause();
    void Resume();
    void Exe();  

private:
    bool CheckIfStopped() const;

private:
    SafePriorityQueue<Task> m_Sque;
    std::jthread m_thread;
    bool m_stop = true;
    std::binary_semaphore m_semPause{1};
    mutable std::mutex m_key;
};

}

#endif
