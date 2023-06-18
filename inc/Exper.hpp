#ifndef EXPER_HPP
#define EXPER_HPP

#include <unordered_map>
#include <string>
#include <string>
#include <ctime>

class Expr
{
public:
    virtual ~Expr() = default;
    virtual double Value(std::unordered_map<std::string, double> a_map = {}) const = 0;
    virtual void Print() const = 0;

};

#endif 

