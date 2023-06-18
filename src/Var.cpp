#include <iostream>
#include <unordered_map>
#include <string>
#include "Var.hpp"

Var::Var(std::string a_var)
: m_var(a_var)
{  
}

double Var::Value(std::unordered_map<std::string, double> a_map) const
{
    // auto s = a_map.find(m_var);
    // if(s != a_map.end()){
    //     std::cout<<s->second;
    //     return s->second;
    // }
    return a_map[m_var];
}

void Var::Print() const
{
    std::cout << m_var;
}