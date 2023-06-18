#include <map>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
#include <cctype>
#include "Expression.hpp"

Expression::Expression(std::map<std::string, double> a_map)
: m_map(a_map)
{
}

double Expression::Calc(std::string a_str)
{
    std::stack<std::string> st;
    std::queue<std::string> q;
    std::queue<std::string> vecOutput;
    q = Split(a_str);
    // while(!q.empty()){
    //     if( q.front().length() > 1 ){ //double
    //         vecOutput.push(q.front());
    //     }else{
    //         if(isOprator(q.front())){
    //             fixStack(st, vecOutput, q.front());
    //         }else if(isClose(q.front())){
    //             fixStackClose(st, vecOutput, q.front());
    //         }else if(isOpen(q.front())){
    //             st.push(q.front());
    //         }else{
    //            double num = getItem(q.front()); 
    //            vecOutput.push(std::to_string(num));
    //         }
    //     }
    //     q.pop();
    // }
    // if(!st.empty()){
    //     vecOutput.push(st.top());
    //     st.pop();
    // }
    // while(!vecOutput.empty()){
    //     std::cout<< vecOutput.front() << std::endl;
    //     vecOutput.pop();
    // }
    return 0.0;
}

double Expression::getItem(std::string a_str)
{
    return m_map[a_str];
}

std::queue<std::string> Split(std::string a_str)
{
    std::queue<std::string> q;
    size_t i = 0;
    while (a_str[i] != '\0') {  
        std::string word = std::string(1, a_str[i]);
        if(a_str[i] == ' '){
            ++i;
            continue;
        }else if(isOprator(word) || isOpen(word) || isClose(word) ){
            q.push(word);
            ++i;
            continue;
        }else{
            ++i;
            while(a_str[i] != ' ' && a_str[i] != '\0' && !isClose(std::to_string(a_str[i]))){
                word += std::string(1, a_str[i]);
                ++i;
            }
            q.push(word);
        }
    }
    while(!q.empty()){
        std::cout<< q.front() << std::endl;
        q.pop();
    }
    return q;
}
// std::queue<std::string> Split(std::string a_str)
// {
//     std::queue<std::string> q;
//     std::stringstream s(a_str);
//     std::string word;
//     while (s >> word) {  
//         q.push(word);
//     }
//     return q;
// }

bool isOprator(std::string a_str)
{
    if( a_str == "*" || a_str == "/" || a_str == "+" || a_str == "-" ){
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

    return true;
}

void fixStack(std::stack<std::string>& a_st, std::queue<std::string>& a_que, std::string& a_str)
{
    while(!a_st.empty() && Priority(a_str) <= Priority(a_st.top())){
        a_que.push(a_st.top());
        a_st.pop();
    }
    a_st.push(a_str);
}

void fixStackClose(std::stack<std::string>& a_st, std::queue<std::string>& a_que, std::string& a_str)
{
    while(!a_st.empty() && Priority(a_st.top()) != 0){
        a_que.push(a_st.top());
        a_st.pop();
    }
    a_st.pop();
}

unsigned int Priority(std::string a_str)
{
    if(a_str == ")" || a_str == "]" || a_str == "}" ){
        return 3;
    }else if(a_str == "*" || a_str == "/" ){
        return 2;
    }else if(a_str == "+" || a_str == "-" ){
        return 1;
    }else if(a_str == "(" || a_str == "[" || a_str == "{"){
        return 0;
    }
    return 4;
}
