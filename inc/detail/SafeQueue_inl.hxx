#include <queue>
#include <functional>
#include <mutex>
#include <ctime>

#include "SafeQueue.hpp"

namespace h72{

template <typename T>
void SafeQueue<T>::Push(T const& a_elm)
{
    std::lock_guard<std::mutex> lock(m_key);
    m_safeQueue.push(a_elm);
    m_sem.release();
}

template <typename T>
void SafeQueue<T>::Push(T&& a_elm)
{
    std::lock_guard<std::mutex> lock(m_key);
    m_safeQueue.push(std::move(a_elm));
    m_sem.release();
}

template <typename T>
void SafeQueue<T>::Pop(T& a_elm)
{
    m_sem.acquire();
    std::lock_guard<std::mutex> lock(m_key);
    a_elm = std::move(m_safeQueue.front());
    m_safeQueue.pop();
}

template <typename T>
bool SafeQueue<T>::IsEmpty() const
{
    std::lock_guard<std::mutex> lock(m_key);
    return m_safeQueue.empty();
}

template <typename T>
size_t SafeQueue<T>::Size() const
{
    std::lock_guard<std::mutex> lock(m_key);
    return m_safeQueue.size();
}

template <typename T>
void  SafeQueue<T>::Move(SafeQueue<std::function<void()>>& a_from)
{
    size_t len = a_from.Size();
    for(size_t i = 0; i < len; ++i){
        T task;
        a_from.Pop(task);
        Push(task);
    }
}

}

