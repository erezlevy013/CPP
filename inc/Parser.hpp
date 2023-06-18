#ifndef PARSER_HPP
#define PARSER_HPP

#include<string>
#include<vector>
#include <unordered_map>
#include <functional>

#include "Exper.hpp"
#include "Token.hpp"

class Parser
{
public:
    Parser() = default;
    Parser(std::unordered_map<std::string, std::function<double(double)>> a_funcs);
    ~Parser() = default;

    Expr* Parse(std::vector<Token> a_vec);

private:
    Expr* newExprOperator(std::string a_str, Expr* a_right, Expr* a_left);

private:
    std::unordered_map<std::string, std::function<double(double)>> m_funcs = {};   
};



#endif

