#ifndef SUB_HPP
#define SUB_HPP
 
#include <unordered_map>
#include <string>
#include "Exper.hpp"

class Sub : public Expr
{
public:
    explicit Sub(Expr* a_left, Expr* a_right);
    ~Sub() = default;

    double Value(std::unordered_map<std::string, double> a_map = {}) const override;
    void Print()  const override;

private:
    Expr* m_left;
    Expr* m_right;
    double m_value;
};

#endif


