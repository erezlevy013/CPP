#include "Token.hpp"

Token::Token(std::string a_value, size_t a_pos)
: m_value(a_value)
, m_pos(a_pos)
, m_kind(FindKind(a_value))
{
}

std::string Token::GetValue() const
{
    return m_value;
}

size_t Token::GetPos() const
{
    return m_pos;
}

Token::Kind Token::GetKind() const
{
    return m_kind;
}

Token::Kind Token::FindKind(std::string a_value)
{
    if(isOprator(a_value)){
        return Token::Kind::OPS;
    }else if(isDigit(a_value)){
        return Token::Kind::NUM;
    }else if(isOpen(a_value)){
        return Token::Kind::OPEN;
    }else if(isClose(a_value)){
        return Token::Kind::CLOSE;
    }
    return Token::Kind::STR;
}

bool isOprator(std::string a_str)
{
    if( a_str == "*" || a_str == "/" || a_str == "+" || a_str == "-" || a_str == "%" || a_str == "^"){
        return true;
    }
    return false;
}

bool isClose(std::string a_str)
{
    if( a_str == ")" || a_str == "}" || a_str == "]"){
        return true;
    }
    return false;
}

bool isOpen(std::string a_str)
{
    if( a_str == "(" || a_str == "{" || a_str == "["){
        return true;
    }
    return false;
}

bool isDigit(std::string a_str)
{
    if(std::isdigit(a_str[0])){
        return true;
    }
    return false;
}
