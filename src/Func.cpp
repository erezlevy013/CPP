#include <iostream>
#include <unordered_map>
#include <string>
#include "Func.hpp"

Func::Func(std::string a_funcName, std::function<double(double)> a_func, Expr* a_arg)
: m_funcName(a_funcName)
, m_func(a_func)
, m_arg(a_arg)
{  
}

double Func::Value(std::unordered_map<std::string, double> a_map) const
{
    return m_func(m_arg->Value(a_map));
}

void Func::Print() const
{
    std::cout << m_funcName;
    std::cout << "(";
    m_arg->Print();
    std::cout << ")";
}