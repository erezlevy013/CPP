#include <functional>
#include <chrono>
#include <thread>

#include "Task.hpp"

namespace h72{

Task::Task(std::function<void()>const& a_func, std::chrono::milliseconds a_milTime)
: m_func(a_func)
, m_milTime(a_milTime)
, m_nextTime(std::chrono::steady_clock::now() + m_milTime)
{
}

Task::Task(Task const& a_task)
: m_func(a_task.m_func)
, m_milTime(a_task.m_milTime)
, m_nextTime(a_task.m_nextTime)
{
}

Task& Task::operator=(Task const& a_task) 
{
    if(this == &a_task){
        return *this;
    }
    m_func = a_task.m_func;
    m_milTime = a_task.m_milTime;
    m_nextTime = a_task.m_nextTime;
    return *this;
}

bool Task::operator<(Task const& a_task) const
{
    return m_nextTime > a_task.m_nextTime;
}

void Task::RunTask() 
{
    if (m_nextTime > std::chrono::steady_clock::now()){
        std::this_thread::sleep_until(m_nextTime);
    }

    try{
        m_func();
    }catch(...){
        throw "bad func";
    }
}

void Task::UpdateNextTime()
{
    m_nextTime = std::chrono::steady_clock::now() + m_milTime; 
}

}
