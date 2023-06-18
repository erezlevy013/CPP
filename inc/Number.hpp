#ifndef NUMBER_HPP
#define NUMBER_HPP

#include <unordered_map>
#include <string>
#include "Exper.hpp"

class Number : public Expr
{
public:
    explicit Number(double a_number);
    ~Number() = default;

    double Value(std::unordered_map<std::string, double> a_map = {}) const override;
    void Print()  const override;

private:
    double m_number;  
};

#endif
