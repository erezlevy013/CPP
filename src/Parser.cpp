#include <stack>
#include <iostream>

#include "Parser.hpp"
#include "Exper.hpp"
#include "Func.hpp"
#include "Number.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Div.hpp"
#include "Mul.hpp"
#include "Pow.hpp"
#include "Modulo.hpp"
#include "Var.hpp"

static std::vector<Token> InToPost(std::vector<Token> a_vecTok, std::unordered_map<std::string, std::function<double(double)>> a_funcs);
static void fixStack(std::stack<Token>& a_st, std::vector<Token>& a_vec, const Token& a_tk);
static void fixStackClose(std::stack<Token>& a_st, std::vector<Token>& a_vec);
static unsigned int Priority(std::string a_str);

Parser::Parser(std::unordered_map<std::string, std::function<double(double)>> a_funcs)
: m_funcs(a_funcs)
{
}


Expr* Parser::Parse(std::vector<Token> a_vec)
{
    std::vector<Token> output = InToPost(a_vec, m_funcs);
    std::cout <<"after\n";
    for(Token i : output){
        std::cout << i.GetValue() << " ";
    }
    std::stack<Expr*> st;
    size_t size = output.size();
    for(size_t i = 0; i < size; ++i){
        if(output[i].GetKind() == Token::Kind::NUM ){
            double d = atof(output[i].GetValue().c_str());
            Expr* num = new Number(d);
            st.push(num);
        }else if(output[i].GetKind() == Token::Kind::STR){
            if(auto s = m_funcs.find(output[i].GetValue()); s != m_funcs.end()){
                Expr* func = new Func(output[i].GetValue(), s->second, st.top());
                st.pop();
                st.push(func);
            }else{
                Expr* num = new Var(output[i].GetValue());
                st.push(num);
            }   
        }else{
            Expr* right = st.top();
            st.pop();
            Expr* left = st.top();
            st.pop();
            st.push(newExprOperator(output[i].GetValue(), left, right));
        }
    }
    return st.top();
}

Expr* Parser::newExprOperator(std::string a_str, Expr* a_left, Expr* a_right)
{
    if(a_str == "*"){
        return new Mul(a_left, a_right);
    }else if(a_str == "/"){
        return new Div(a_left, a_right);
    }else if(a_str == "+"){
        return new Add(a_left, a_right);
    }else if(a_str == "^"){
        return new Pow(a_left, a_right);
    }else if(a_str == "%"){
        return new Modulo(a_left, a_right);
    }
    return new Sub(a_left, a_right);
}

static std::vector<Token> InToPost(std::vector<Token> a_vecTok, std::unordered_map<std::string, std::function<double(double)>> a_funcs)
{
    std::stack<Token> st;
    std::vector<Token> vecOutput;
    for(size_t i = 0; i < a_vecTok.size(); ++i){
        if( a_vecTok[i].GetKind() == Token::Kind::NUM ){ 
            vecOutput.push_back(a_vecTok[i]);
        }else if( a_vecTok[i].GetKind() == Token::Kind::OPS){
            fixStack(st, vecOutput, a_vecTok[i]);
            st.push(a_vecTok[i]);
        }else if(a_vecTok[i].GetKind() == Token::Kind::CLOSE){
            fixStackClose(st, vecOutput);
        }else if(a_vecTok[i].GetKind() == Token::Kind::OPEN){
            st.push(a_vecTok[i]);
        }else if(auto s = a_funcs.find(a_vecTok[i].GetValue()); s != a_funcs.end()){
            fixStack(st, vecOutput, a_vecTok[i]);
            st.push(a_vecTok[i]);
        }else{ 
            vecOutput.push_back(a_vecTok[i]);
        }
    }
    while(!st.empty()){
        vecOutput.push_back(st.top());
        st.pop();
    }
    return vecOutput;
}

static void fixStack(std::stack<Token>& a_st, std::vector<Token>& a_vec, const Token& a_tk)
{
    while(!a_st.empty() && Priority(a_tk.GetValue()) <= Priority(a_st.top().GetValue())){
        a_vec.push_back(a_st.top());
        a_st.pop();
    }
    
}

static void fixStackClose(std::stack<Token>& a_st, std::vector<Token>& a_vec)
{
    while(!a_st.empty() && Priority(a_st.top().GetValue()) != 0){
        a_vec.push_back(a_st.top());
        a_st.pop();
    }
    a_st.pop();
}

static unsigned int Priority(std::string a_str)
{
    if(a_str == "^"){
        return 4;
    }else if(a_str == ")" || a_str == "]" || a_str == "}" ){
        return 3;
    }else if(a_str == "*" || a_str == "/" ){
        return 2;
    }else if(a_str == "+" || a_str == "-" ){
        return 1;
    }else if(a_str == "(" || a_str == "[" || a_str == "{"){
        return 0;
    }
    return 5;
}
