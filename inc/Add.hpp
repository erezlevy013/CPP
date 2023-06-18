#ifndef ADD_HPP
#define ADD_HPP

#include <unordered_map>
#include <string>
#include "Exper.hpp"

class Add : public Expr
{
public:
    explicit Add(Expr* a_left, Expr* a_right);
    ~Add() = default;
    
    double Value(std::unordered_map<std::string, double> a_map = {}) const override;
    void Print()  const override;


private:
    Expr* m_left;
    Expr* m_right;
    double m_value;
};

#endif



