#ifndef MY_EXCEPTION_HPP
#define MY_EXCEPTION_HPP

#include <exception>
#include <string>

namespace h72{

class MyException : public std::exception
{
public:
    explicit MyException(std::string a_str);
    ~MyException() = default;

private:
    std::string m_str;
};

MyException::MyException(std::string a_str) 
: m_str(a_str)
{
}

}



#endif /* EXCEPT_HPP */
