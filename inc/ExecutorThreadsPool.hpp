#ifndef EXECUTOR_THREADS_POOL_HPP
#define EXECUTOR_THREADS_POOL_HPP

#include <functional>
#include <vector>
#include <thread>
#include <mutex>
#include <semaphore>
#include <unordered_map>

#include "SafeDeQueue.hpp"

namespace h72{

class ExecutorThreadsPool
{
public:
    explicit ExecutorThreadsPool(size_t a_numOfThreads);
    ~ExecutorThreadsPool();

    void Submit(std::function<void()>& a_task);
    void Submit(std::function<void()>&& a_task);

    void Add(size_t a_numOfThreads);

    void Shutdown();
    std::vector<std::function<void()>> ShutdownNow();
    void Remove(size_t a_numOfThreads);

private:
    void Run();
    bool CheckShutdown();
    void fillPoisonBack(size_t a_numOfPoison);
    void fillPoisonFront(size_t a_numOfPoison);
    void DeleteThreads();
    

private:
    class Poison : public std::exception{};

private:
    SafeDeQueue<std::function<void()>> m_Sque;
    std::unordered_map<std::thread::id, std::thread> m_threads;
    SafeDeQueue<std::thread::id> m_deadThreads;
    std::binary_semaphore m_semRemove{0};
    std::mutex m_key;
    bool m_shutdown = false;
    size_t m_numToRemove = 0;

}; 

}

#endif
