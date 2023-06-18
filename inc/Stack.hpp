#ifndef STACK_HPP
#define STACK_HPP

#include <cstddef> /*size_t*/
#include <memory>

class Stack
{
public:
    explicit Stack(size_t a_capacity = 100); /*ctor*/ 
    Stack(Stack const& a_source); /*cctor*/
    Stack(Stack&& a_source); /*mctor*/
    ~Stack() = default; /*dtor*/

    Stack& operator=(Stack const& a_source); /* copy assignment*/
    Stack& operator=(Stack&& a_source); /*move assignment*/

    bool Push(int a_item); /*Add item to end.*/
    bool Pop(int& a_item); /*Delete item from the end.*/
    void Clear(); /* Remove all*/
    void MoveTo(Stack& a_dest);
    void Copy(const Stack& a_source);
    void CopyRev(const Stack& a_source);

    int const& Top() const; /*Return the value of an element*/

    size_t Capacity() const; /*Get BlockSize*/
    size_t Size() const; /*Get Size*/
    bool Empty() const;
    bool Full() const;
    void Print() const; /*print all the elements.*/    
    
private:
    std::unique_ptr<int[]> m_stack;
    size_t m_capacity ;
    size_t m_size = 0; 
};

bool Drain(Stack& a_dest, Stack& a_source);
bool Ability(const size_t a_size, const size_t a_len);

#endif /* STACK_H */
