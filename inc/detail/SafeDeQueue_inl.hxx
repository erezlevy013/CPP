#include <deque>
#include <mutex>

#include "SafeDeQueue.hpp"

namespace h72{

template <typename T>
void SafeDeQueue<T>::Push_Back(T const& a_elm)
{
    std::lock_guard<std::mutex> lock(m_key);
    m_safeQueue.push_back(a_elm);
    m_sem.release();
}

template <typename T>
void SafeDeQueue<T>::Push_Back(T&& a_elm)
{
    std::lock_guard<std::mutex> lock(m_key);
    m_safeQueue.push_back(std::move(a_elm));
    m_sem.release();
}

template <typename T>
void SafeDeQueue<T>::Push_Front(T const& a_elm)
{
    std::lock_guard<std::mutex> lock(m_key);
    m_safeQueue.push_front(a_elm);
    m_sem.release();
}

template <typename T>
void SafeDeQueue<T>::Push_Front(T&& a_elm)
{
    std::lock_guard<std::mutex> lock(m_key);
    m_safeQueue.push_front(std::move(a_elm));
    m_sem.release();
}

template <typename T>
void SafeDeQueue<T>::Pop_Back(T& a_elm)
{
    m_sem.acquire();
    std::lock_guard<std::mutex> lock(m_key);
    a_elm = std::move(m_safeQueue.back());
    m_safeQueue.pop_back();
}

template <typename T>
void SafeDeQueue<T>::Pop_Front(T& a_elm)
{
    m_sem.acquire();
    std::lock_guard<std::mutex> lock(m_key);
    a_elm = std::move(m_safeQueue.front());
    m_safeQueue.pop_front();
}

template <typename T>
bool SafeDeQueue<T>::IsEmpty() const
{
    std::lock_guard<std::mutex> lock(m_key);
    return m_safeQueue.empty();
}

template <typename T>
size_t SafeDeQueue<T>::Size() const
{
    std::lock_guard<std::mutex> lock(m_key);
    return m_safeQueue.size();
}

}

