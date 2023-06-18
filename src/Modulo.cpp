#include <iostream>
#include <cmath>
#include <unordered_map>
#include <string>
#include "Modulo.hpp"

Modulo::Modulo(Expr* a_left, Expr* a_right)
: m_left(a_left)
, m_right(a_right)
, m_value(Value())
{
}

double Modulo::Value(std::unordered_map<std::string, double> a_map) const
{
    return std::fmod(m_left->Value(a_map), m_right->Value(a_map));
}

void Modulo::Print() const
{
    std::cout << "(";
    m_left->Print();
    std::cout << "%";
    m_right->Print(); 
    std::cout << ")";
}
