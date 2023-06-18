#include <iostream>
#include <unordered_map>
#include <string>
#include "Sub.hpp"

Sub::Sub(Expr* a_left, Expr* a_right)
: m_left(a_left)
, m_right(a_right)
, m_value(Value())
{
}

double Sub::Value(std::unordered_map<std::string, double> a_map) const
{
    return m_left->Value(a_map) - m_right->Value(a_map);
}

void Sub::Print() const
{
    std::cout << "(";
    m_left->Print();
    std::cout << "-";
    m_right->Print(); 
    std::cout << ")";
}
