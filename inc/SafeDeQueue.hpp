#ifndef SAFE_DEQUEUE_HPP
#define SAFE_DEQUEUE_HPP

#include <deque>
#include <functional>
#include <mutex>
#include <ctime>
#include <semaphore>

namespace h72{

template <typename T>
class SafeDeQueue
{
public:
    explicit SafeDeQueue() = default;
    ~SafeDeQueue() = default;

    void Push_Back(T const& a_elm);
    void Push_Back(T&& a_elm);

    void Push_Front(T const& a_elm);
    void Push_Front(T&& a_elm);

    void Pop_Back(T& a_elm);
    void Pop_Front(T& a_elm);

    bool IsEmpty() const;
    size_t Size() const;

private:
    std::deque<T> m_safeQueue;
    std::counting_semaphore<> m_sem{0};
    mutable std::mutex m_key;
};

}

#include "detail/SafeDeQueue_inl.hxx"

#endif
