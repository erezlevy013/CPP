#ifndef MUL_HPP
#define MUL_HPP

#include <unordered_map>
#include <string>
#include "Exper.hpp"

class Mul : public Expr
{
public:
    explicit Mul(Expr* a_left, Expr* a_right);
    ~Mul() = default;

    double Value(std::unordered_map<std::string, double> a_map = {}) const override;
    void Print()  const override;

private:
    Expr* m_left;
    Expr* m_right;
    double m_value;  
};

#endif

