#include <functional>
#include <vector>
#include <thread>
#include <mutex>
#include <semaphore>
#include <unordered_map>

#include "ExecutorThreadsPool.hpp"


#include <iostream>
namespace h72{

ExecutorThreadsPool::ExecutorThreadsPool(size_t a_numOfThreads)
{
    Add(a_numOfThreads);
}

ExecutorThreadsPool::~ExecutorThreadsPool()
{
    // DeleteThreads();
    for(auto& thread : m_threads){
        thread.second.detach();
    }
}

void ExecutorThreadsPool::Submit(std::function<void()>& a_task)
{      
    std::lock_guard<std::mutex> lock(m_key);
    if(!m_shutdown){  
        m_Sque.Push_Back(std::move(a_task));
    }
}

void ExecutorThreadsPool::Submit(std::function<void()>&& a_task)
{
    std::lock_guard<std::mutex> lock(m_key);
    if(!m_shutdown){
        m_Sque.Push_Back(std::move(a_task));
    }
}

void ExecutorThreadsPool::Add(size_t a_numOfThreads)
{
    std::lock_guard<std::mutex> lock(m_key);
    for(size_t i = 0; i < a_numOfThreads; ++i){
        std::thread t(&ExecutorThreadsPool::Run, this);
        std::thread::id tID = t.get_id();
        m_threads.emplace(std::move(tID), std::move(t));
    }
}

void ExecutorThreadsPool::Run()
{
    std::thread::id this_id = std::this_thread::get_id();
    while(true){ 
        std::function<void()> task;
        m_Sque.Pop_Front(task);  
        try{
            task();
        }catch(Poison const& p){
            std::cout<<"catch"<<std::endl;
            m_deadThreads.Push_Back(this_id);
            return;
        }catch(...){
        }
    }
}

void ExecutorThreadsPool::Shutdown()
{
    std::lock_guard<std::mutex> lock(m_key);
    m_shutdown = true;

    fillPoisonBack(m_threads.size());
    DeleteThreads();
}

std::vector<std::function<void()>> ExecutorThreadsPool::ShutdownNow()
{
    std::lock_guard<std::mutex> lock(m_key);
    m_shutdown = true;

    fillPoisonFront(m_threads.size());
    DeleteThreads();

    std::vector<std::function<void()>> vec; //empty
    return vec;
}

void ExecutorThreadsPool::Remove(size_t a_numOfThreads)
{
    std::lock_guard<std::mutex> lock(m_key);
    if(a_numOfThreads > m_threads.size()){
        return;
    }
    m_numToRemove = a_numOfThreads;

    fillPoisonFront(m_numToRemove);

    DeleteThreads();
}

void ExecutorThreadsPool::fillPoisonBack(size_t a_numOfPoison)
{
    for(size_t i = 0; i < a_numOfPoison; ++i){
        m_Sque.Push_Back([](){throw Poison();});
    }
}

void ExecutorThreadsPool::fillPoisonFront(size_t a_numOfPoison)
{
    for(size_t i = 0; i < a_numOfPoison; ++i){
        m_Sque.Push_Front([](){throw Poison();});
    }
}

void ExecutorThreadsPool::DeleteThreads()
{
    while(m_numToRemove){
        std::thread::id tID;
        m_deadThreads.Pop_Front(tID);
        m_threads[tID].join();
        m_threads.erase(tID);
        --m_numToRemove;
    }
}

}
