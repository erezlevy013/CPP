#include <algorithm>
#include "Lexer.hpp"


Lexer::Lexer(std::vector<std::string> a_vecOps)
: m_vecOps(a_vecOps)
{
}

std::vector<Token> Lexer::Split(std::string a_str)
{
    std::vector<Token> output;
    size_t i = 0;
    while(a_str[i] != '\0') {  
        std::string word = std::string(1, a_str[i]);
        if(a_str[i] == ' '){
            ++i;
            continue;
        }else if(std::find(m_vecOps.begin(), m_vecOps.end(), word) != m_vecOps.end() || isOpen(word) || isClose(word) ){
            Token tk(word, i);
            output.push_back(tk);
            ++i;
            continue;
        }else{
            ++i;
            while(a_str[i] != ' ' && a_str[i] != '\0' && !isClose(std::string(1,a_str[i])) && !isOpen(std::string(1,a_str[i])) && !isOprator(std::string(1,a_str[i]))){
                word += std::string(1, a_str[i]);
                ++i;
            }
            Token tk(word, i - word.length());
            output.push_back(tk);
        }
    }
    return output;
}
