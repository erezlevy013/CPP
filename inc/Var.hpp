#ifndef VAR_HPP
#define VAR_HPP

#include <unordered_map>
#include <string>
#include "Exper.hpp"

class Var : public Expr
{
public:
    explicit Var(std::string a_var);
    ~Var() = default;

    double Value(std::unordered_map<std::string, double> a_map = {}) const override;
    void Print()  const override;

private:
    std::string m_var;  
};

#endif
