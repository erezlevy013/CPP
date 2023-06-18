#ifndef SAFE_PQUEUE_HPP
#define SAFE_PQUEUE_HPP

#include <queue>
#include <functional>
#include <mutex>
#include <ctime>
#include <semaphore>

namespace h72{

template <typename T>
class SafePriorityQueue
{
public:
    explicit SafePriorityQueue() = default;
    ~SafePriorityQueue() = default;

    void Push(T const& a_elm);
    void Push(T&& a_elm);
    void Pop(T& a_elm);

    bool IsEmpty() const;
    size_t Size() const;

private:
    std::priority_queue<T> m_safeQueue;
    std::counting_semaphore<> m_sem{0};
    mutable std::mutex m_key;
};

}

#include "detail/SafePriorityQueue_inl.hxx"

#endif
