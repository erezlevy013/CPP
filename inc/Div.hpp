#ifndef DIV_HPP
#define DIV_HPP

#include <unordered_map>
#include <string>
#include "Exper.hpp"

class Div : public Expr
{
public:
    explicit Div(Expr* a_left, Expr* a_right);
    ~Div() = default;

    double Value(std::unordered_map<std::string, double> a_map = {}) const override;
    void Print()  const override;


private:
    Expr* m_left;
    Expr* m_right;
    double m_value;
};

#endif
