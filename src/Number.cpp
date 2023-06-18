#include <iostream>
#include <unordered_map>
#include <string>
#include "Number.hpp"

Number::Number(double a_number)
: m_number(a_number)
{
}

double Number::Value(std::unordered_map<std::string, double> a_map) const
{
    return m_number;
}

void Number::Print() const
{
    std::cout << m_number;
}