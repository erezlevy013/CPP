#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>
#include "Token.hpp"

class Lexer
{
public:
    explicit Lexer(std::vector<std::string> a_vecOps);
    ~Lexer() = default;

    std::vector<Token> Split(std::string a_str);
private:
    std::vector<std::string> m_vecOps;   
};


#endif