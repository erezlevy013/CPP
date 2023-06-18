#include <cassert> /*assert*/
#include <cstdlib> /*malloc size_t*/
#include <iostream> /*cout*/
#include <memory>
#include "Stack.hpp"




Stack::Stack(size_t a_capacity)
: m_stack(new int[a_capacity])
, m_capacity(a_capacity)
{
}

Stack::Stack(Stack const& a_source)
: m_stack(new int[a_source.m_capacity])
, m_capacity(a_source.m_capacity)
, m_size(a_source.m_size)
{
    // size_t len = a_source.m_size;
    // for(size_t i = 0; i < len; ++i){
    //     m_stack.get()[i] = a_source.m_stack.get()[i]; 
    // }
    std::copy(a_source.m_stack.get(), a_source.m_stack.get()+a_source.m_capacity, m_stack.get());
}

Stack::Stack(Stack&& a_source)
: m_stack(a_source.m_stack.release())
, m_capacity(a_source.m_capacity)
, m_size(a_source.m_size)
{
    // m_stack.reset(a_source.m_stack.get());
    // a_source.m_stack = nullptr;
    m_stack = std::move(a_source.m_stack);
}

Stack& Stack::operator=(Stack const& a_source)
{
    if(this == &a_source){
        return *this;
    }
    if(m_capacity < a_source.m_capacity){
        m_stack.reset(new int[a_source.m_capacity]);
    }
    std::copy(a_source.m_stack.get(), a_source.m_stack.get()+a_source.m_capacity, m_stack.get());
    m_capacity = a_source.m_capacity;
    m_size = a_source.m_size;
    return *this;
}

Stack& Stack::operator=(Stack&& a_source) 
{
    if(this == &a_source){
        return *this;
    }
    //m_stack = std::move(a_source.m_stack);

    m_stack = std::move(a_source.m_stack);
    m_capacity = a_source.m_capacity;
    m_size = a_source.m_size;

    return *this;
}

bool Stack::Push(int a_item)
{
    if(Full()){
        return false;
    }

    m_stack.get()[m_size++] = a_item;

    return true;
}

bool Stack::Pop(int& a_item)
{
    if(Empty()){
        return false;
    }

    a_item = m_stack.get()[--m_size];

    return true;
}

int const& Stack::Top() const
{
    assert(m_size > 0);
    return m_stack.get()[m_size -1];
}

size_t Stack::Capacity() const
{
    return m_capacity;
}

size_t Stack::Size() const
{
    return m_size;
}

bool Stack::Empty() const
{
    return m_size == 0;
}

bool Stack::Full() const
{
    return Size() == Capacity();
}

void Stack::Print() const
{
    if(Empty()){
        std::cout << "[]\n";
        return;
    }
    std::cout << "[";
    for(size_t i = 0; i < m_size -1;  ++i){
        std::cout << m_stack.get()[i] << ", ";
    }
    std::cout << m_stack.get()[m_size - 1] << "]" << std::endl;
}

void Stack::Clear()
{
    m_size = 0;
}

void Stack::MoveTo(Stack& a_dest)
{
    size_t len = m_size;
    if( Ability(len, m_size) ){
        return;
    }
    for(size_t i = 0; i < len; ++i){
        int val;
        Pop(val);
        a_dest.Push(val); 
    }
}

void Stack::Copy(const Stack& a_source)
{
    size_t len = a_source.m_size;
    if( Ability(len, m_size) ){
        return;
    }
    for(size_t i = 0; i < len; ++i){
        int x = a_source.m_stack.get()[i];
        Push(x); 
    }
}

void Stack::CopyRev(const Stack& a_source)
{
    size_t len = a_source.m_size;
    if( Ability(len, m_size) ){
        return;
    }
    for(size_t i = len ; i > 0; --i){
        int x = a_source.m_stack.get()[i-1];
        Push(x); 
    }
}

bool Drain(Stack& a_dest, Stack& a_source)
{
    size_t len = a_source.Size();
    if( Ability(a_dest.Capacity() - a_dest.Size() , len) ){
        return false;
    }
    Stack temp(len);
    a_source.MoveTo(temp);
    temp.MoveTo(a_dest);

    return true;
}

bool Ability(const size_t a_size, const size_t a_len)
{
    return a_size < a_len;
}
