#include <iostream>
#include <algorithm>

#include "../List.hpp"

namespace h72 {

template<typename T>
class List<T>::Node
{
public:
    Node() = default;
    Node(const Node& a_node) = default;
    explicit Node(T const& a_data, Node* a_next = nullptr, Node* a_prev = nullptr);
    Node& operator=(const Node& n) = default;

    T getData();
    Node* getNext();
    Node* getPrev();

    const T getData() const;
    Node const* getNext() const;
    Node const* getPrev() const; 

    void SetData(T const& a_date);
    void SetNext(Node* a_next);
    void SetPrev(Node* a_prev);

private:
    T m_data;
    Node* m_next; 
    Node* m_prev; 
}; 

template<typename T>
List<T>::Node::Node(T const& a_data, Node* a_next, Node* a_prev)
: m_data(a_data)
, m_next(a_next)
, m_prev(a_prev)
{

}

template<typename T>
List<T>::List()
: m_head()  
, m_tail()
{
    m_head.SetNext(&m_tail);
    m_head.SetPrev(&m_head);
    m_tail.SetNext(&m_tail);
    m_tail.SetPrev(&m_head);
}

template<typename T>
List<T>::List(const List& list)
: m_head()
, m_tail()                        
{
    m_head.SetNext(&m_tail);
    m_head.SetPrev(&m_head);
    m_tail.SetNext(&m_tail);
    m_tail.SetPrev(&m_head);

    Node const* head = list.m_head.getNext();
    while(head != &list.m_tail){
        PushTail(head->getData());
        head = head->getNext();
    }
}

template<typename T>
List<T>& List<T>::operator=(const List& a_list)
{
    while(!Empty()){
        T x;
        PopHead(x);
    }
    Node const* head = a_list.m_head.getNext();
    while(head != &a_list.m_tail){
        PushTail(head->getData());
        head = head->getNext();
    }
    return *this;
}

// template<typename T>
// List<T>& List<T>::operator=(const List& a_list)
// {
//     if( this != &a_list){
//         List<T> t(a_list);
//         List<T> *temp = this;
//         *this = t;
//         t = *temp;
//     }
//     return *this;
// }

template<typename T>
List<T>::~List()
{
    Node* head = m_head.getNext();
    while(head != &m_tail){
        Node* next = head->getNext();
        delete head;
        head = next;
    }
}

template<typename T>
bool List<T>::PushHead(T const& a_item)
{
    Node* newNode = new Node(a_item);
    Insert(newNode, m_head.getNext());
    return true;
}

template<typename T>
bool List<T>::PushTail(T const& a_item)
{
    Node* newNode = new Node(a_item);
    Insert(newNode, &m_tail);
    return true;
}

template<typename T>
bool List<T>::PopHead( T& a_pItem)
{
    Node* base;
    base = m_head.getNext();
    a_pItem = base->getData();
    Pop(base); 
    delete base;
    return true;
}

template<typename T>
bool List<T>::PopTail( T& a_pItem)
{
    Node * base;
    base = m_tail.getPrev();
    a_pItem = base->getData();
	Pop(base);
    delete base;
    return true;
}

template<typename T>
void List<T>::Insert(List<T>::Node* a_node1, List<T>::Node* a_node2)
{
    a_node1->SetPrev(a_node2->getPrev());
	a_node1->SetNext(a_node2);
	a_node2->getPrev()->SetNext(a_node1);
	a_node2->SetPrev(a_node1);
}

template<typename T>
void List<T>::Pop(List<T>::Node* a_node)
{
    a_node->getNext()->SetPrev(a_node->getPrev());
    a_node->getPrev()->SetNext(a_node->getNext());
}

template<typename T>
size_t List<T>::Size() const
{
    size_t count = 0;
    Node const* head = m_head.getNext();
    while(head != &m_tail){
        count++;
        head = head->getNext();
    }
    return count;
}

template<typename T>
bool List<T>::Contains(T a_item) const
{
    Node const* head = m_head.getNext();
    while(head != &m_tail){
        if(head->getData() == a_item){
            return true;
        }
        head = head->getNext();
    }
    return false;
}

template<typename T>
typename List<T>::Node* List<T>::Reverse(typename List<T>::Node* a_node)
{
    Node* temp = a_node->getNext();
    a_node->SetNext(a_node->getPrev());
    a_node->SetPrev(temp);
    if(a_node == a_node->getPrev()){
        return a_node;
    }
    return Reverse(a_node->getPrev());  
}

template<typename T>
void List<T>::Reverse()
{
    if(Size() <= 1){
        return;
    } 
    Reverse(&m_head);
    std::swap(m_head, m_tail);
    Node * temp = m_tail.getNext();
    m_tail.SetNext(m_head.getPrev());
    m_head.SetPrev(temp);

    m_tail.getPrev()->SetNext(m_tail.getNext());
    m_head.getNext()->SetPrev(m_head.getPrev());
}

template<typename T>
bool List<T>::Empty() const
{
    return m_head.getNext() == &m_tail;
}

template<typename T>
typename List<T>::Node const& List<T>::getHead() const
{
    return m_head;
}

template<typename T>
typename List<T>::Node const& List<T>::getTail() const
{
    return m_tail;
}

template<typename T>
typename List<T>::Node& List<T>::getHead()
{
    return m_head;
}

template<typename T>
typename List<T>::Node& List<T>::getTail()
{
    return m_tail;
}

template<typename T>
const T List<T>::Node::getData() const
{
    return m_data;
}

template<typename T>
typename List<T>::Node const* List<T>::Node::getNext() const
{
    return m_next;
}

template<typename T>
typename List<T>::Node const* List<T>::Node::getPrev() const
{
    return m_prev;
}

template<typename T>
T List<T>::Node::getData()
{
    return m_data;
}

template<typename T>
typename List<T>::Node* List<T>::Node::getNext()
{
    return m_next;
}

template<typename T>
typename List<T>::Node* List<T>::Node::getPrev()
{
    return m_prev;
}

template<typename T>
void List<T>::Node::SetData(T const& a_date)
{
    m_data = a_date;
}

template<typename T>
void List<T>::Node::SetNext(Node* a_next)
{
    m_next = a_next;
}

template<typename T>
void List<T>::Node::SetPrev(Node* a_prev)
{
    m_prev = a_prev;
}

template<typename T>
bool List<T>::operator==(List<T> const& a_list) const
{
    if(Size() != a_list.Size())
    {
        return false;
    }

    typename List<T>::Node const* headFirst = getHead().getNext();
    typename List<T>::Node const* headSecond = a_list.getHead().getNext();
    size_t len = Size();
    for(size_t i = 0; i < len; ++i){
        if(headFirst->getData() != headSecond->getData()){
            return false;
        }
        headFirst = headFirst->getNext();
        headSecond = headSecond->getNext();
    } 
    return true;
}

template<typename T>
bool operator==(List<T>const& a_first, List<T>const& a_second)
{
    return a_first == a_second;
}

template<typename T>
bool operator!=(List<T> const& a_first, List<T> const& a_second)
{
    return !(a_first == a_second);
}

template<typename T>
std::ostream& List<T>::Print(std::ostream& a_out) const
{
    typename List<T>::Node const* head = getHead().getNext();
    size_t len = Size() - 1;
    a_out <<  "[";
    while(len){
        a_out << head->getData() << ", ";
        head = head->getNext();
        --len;
    }
    a_out << head->getData() << "]" <<  std::endl;
    return a_out;
}

template<typename T>
std::ostream& operator<<(std::ostream& a_out, const List<T>& a_list)
{
    return a_list.Print(a_out);
}


} //namespace h72


