#ifndef SAFE_QUEUE_HPP
#define SAFE_QUEUE_HPP

#include <queue>
#include <functional>
#include <mutex>
#include <ctime>
#include <semaphore>

namespace h72{

template <typename T>
class SafeQueue
{
public:
    explicit SafeQueue() = default;
    ~SafeQueue() = default;

    void Push(T const& a_elm);
    void Push(T&& a_elm);
    void Pop(T& a_elm);

    bool IsEmpty() const;
    size_t Size() const;

    void Move(SafeQueue<std::function<void()>>& a_from);

private:
    std::queue<T> m_safeQueue;
    std::counting_semaphore<> m_sem{0};
    mutable std::mutex m_key;
};

}

#include "detail/SafeQueue_inl.hxx"

#endif
