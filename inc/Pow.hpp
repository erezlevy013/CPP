#ifndef POW_HPP
#define POW_HPP

#include <unordered_map>
#include <string>
#include "Exper.hpp"

class Pow : public Expr
{
public:
    explicit Pow(Expr* a_left, Expr* a_right);
    ~Pow() = default;
    
    double Value(std::unordered_map<std::string, double> a_map = {}) const override;
    void Print()  const override;


private:
    Expr* m_left;
    Expr* m_right;
    double m_value;
};

#endif