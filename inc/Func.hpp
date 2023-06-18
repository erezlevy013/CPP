#ifndef FUNC_HPP
#define FUNC_HPP

#include <unordered_map>
#include <string>
#include <functional>
#include "Exper.hpp"

class Func : public Expr
{
public:
    explicit Func(std::string a_funcName, std::function<double(double)> a_func, Expr* a_arg);
    ~Func() = default;

    double Value(std::unordered_map<std::string, double> a_map = {}) const override;
    void Print()  const override;

private:
    std::string m_funcName;  
    std::function<double(double)> m_func;
    Expr* m_arg;
};

#endif