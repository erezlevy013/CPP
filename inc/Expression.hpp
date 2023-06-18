#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <map>
#include <queue>
#include <string>
#include <stack>

class Expression
{
public:
    Expression(std::map<std::string, double> a_map);
    ~Expression() = default;

    double Calc(std::string a_str);
    double getItem(std::string a_str);
private:
    std::map<std::string, double> m_map;
};

std::queue<std::string> Split(std::string a_str);
bool isOprator(std::string a_str);
bool isClose(std::string a_str);
bool isOpen(std::string a_str);
bool isDigit(std::string a_str);
void fixStack(std::stack<std::string>& a_st, std::queue<std::string>& q,  std::string& a_str);
void fixStackClose(std::stack<std::string>& a_st, std::queue<std::string>& a_que,  std::string& a_str);
unsigned int Priority(std::string a_str);






#endif
