#include <queue>
#include <functional>
#include <mutex>
#include <ctime>

#include "SafePriorityQueue.hpp"

namespace h72{

template <typename T>
void SafePriorityQueue<T>::Push(T const& a_elm)
{
    std::lock_guard<std::mutex> lock(m_key);
    m_safeQueue.push(a_elm);
    m_sem.release();
}

template <typename T>
void SafePriorityQueue<T>::Push(T&& a_elm)
{
    std::lock_guard<std::mutex> lock(m_key);
    m_safeQueue.push(std::move(a_elm));
    m_sem.release();
}

template <typename T>
void SafePriorityQueue<T>::Pop(T& a_elm)
{
    m_sem.acquire();
    std::lock_guard<std::mutex> lock(m_key);
    a_elm = std::move(m_safeQueue.top());
    m_safeQueue.pop();
}

template <typename T>
bool SafePriorityQueue<T>::IsEmpty() const
{
    std::lock_guard<std::mutex> lock(m_key);
    return m_safeQueue.empty();
}

template <typename T>
size_t SafePriorityQueue<T>::Size() const
{
    std::lock_guard<std::mutex> lock(m_key);
    return m_safeQueue.size();
}

}

