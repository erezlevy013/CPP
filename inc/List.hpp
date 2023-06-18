#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef> /*size_t*/
#include <iostream> /*cout, <<*/

namespace h72 {

template<typename T>
class List
{
public:
    List();
    List(const List& a_list);
    List& operator=(const List& a_list); 
    ~List();

    bool PushHead(T const& a_item);
    bool PushTail(T const& a_item);
    bool PopHead( T& a_pItem);
    bool PopTail( T& a_pItem);

    void Reverse();

    bool Empty() const;
    size_t Size() const;
    bool Contains(T a_item) const;

    bool operator==(List<T> const& a_list) const;
    std::ostream& Print(std::ostream& a_out) const;
    
private:
    class Node;
    void Insert(List<T>::Node* a_node1, List<T>::Node* a_node2);
    void Pop(List<T>::Node* a_node);
    Node* Reverse(typename List<T>::Node* a_node);
    
    Node const& getHead() const;
    Node const& getTail() const;
    Node& getHead();
    Node& getTail();

private:
    Node m_head;
    Node m_tail;
};

template<typename T>
bool operator==(List<T> const& a_first, List<T> const& a_second);

template<typename T>
bool operator!=(List<T> const& a_first, List<T> const& a_second);

template<typename T>
std::ostream& operator<<(std::ostream& a_out, const List<T>& a_list);

} //namespace h72

#include "detail/List_inl.hxx"

#endif /* LIST_HPP */

