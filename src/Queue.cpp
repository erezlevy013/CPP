#include <cassert> /*assert*/
#include <cstdlib> /*malloc size_t*/
#include <iostream> /*cout*/
#include "Queue.hpp"


Queue::Queue() 
: m_in()
, m_out()
{
}

Queue::Queue(size_t a_capacity) 
: m_in(a_capacity)
, m_out(a_capacity)
{
}

bool Queue::Enqueue(int a_item)
{
    if(Full()){
        return false;
    }

    if( m_in.Full() ){
        m_in.MoveTo(m_out);
    }
    m_in.Push(a_item);

    return true;
}

bool Queue::Dequeue(int& a_item)
{
    if(Empty()){
        return false;
    }

    if( m_out.Empty() ){
        m_in.MoveTo(m_out);
    }
    int x;
    m_out.Pop(x);
    
    return x;
}

size_t Queue::Size() const
{
    return m_in.Size() + m_out.Size();
}
    
bool Queue::Empty() const
{
    return m_in.Size() + m_out.Size() == 0;
}

bool Queue::Full() const
{
    return m_in.Size() == m_in.Capacity() && !m_out.Empty();
}

void Queue::Print() const
{
    Stack t(Size());
    t.CopyRev(m_in);
    t.Copy(m_out);
    t.Print();
}
