#include "Executor.hpp"
#include "SafePriorityQueue.hpp"
#include "Task.hpp"

namespace h72{

Executor::Executor()
: m_Sque()
, m_thread(std::move(std::jthread(&Executor::Exe, this)))
{
}

Executor::~Executor()
{
    m_thread.join();
}

void Executor::Add(Task const& a_task)
{
    m_Sque.Push(a_task);
}

void Executor::Add(Task&& a_task)
{
    m_Sque.Push(std::move(a_task));
}

void Executor::Exe()
{
    while(CheckIfStopped()){
        m_semPause.acquire();
        Task task;
        m_Sque.Pop(task);
        try{
            task.RunTask();
        }catch(...){
            m_semPause.release();
            continue;
        }
        task.UpdateNextTime();
        m_Sque.Push(task);  
        m_semPause.release();
    }
}

void Executor::Run()
{
    std::lock_guard<std::mutex> lock(m_key);
    m_stop = false;
}

void Executor::Shutdown()
{
    std::lock_guard<std::mutex> lock(m_key);
    m_stop = true;
}

void Executor::Pause()
{
    std::lock_guard<std::mutex> lock(m_key);
    m_semPause.acquire();
}

void Executor::Resume()
{
    std::lock_guard<std::mutex> lock(m_key);
    m_semPause.release();
}

bool Executor::CheckIfStopped() const
{
    std::lock_guard<std::mutex> lock(m_key);
    return !m_stop;
}

}
