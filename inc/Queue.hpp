#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstddef> /*size_t*/

#include "Stack.hpp"

class Queue
{   
public:
    explicit Queue(size_t a_capacity); /*ctor*/ 
    Queue(); /* def ctor*/ 
    
    bool Enqueue(int a_item);/* Add item to end*/
    bool Dequeue(int& a_item); /*Remove item from the head*/
    
    size_t Size() const;
    bool Empty() const;
    bool Full() const;
    void Print() const;

private:
    Stack m_in;
    Stack m_out;
};

#endif /*QUEUE_HPP*/
