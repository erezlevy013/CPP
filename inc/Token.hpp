#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

class Token
{
public:
    explicit Token(std::string a_value, size_t a_pos);
    ~Token() = default;

    enum class Kind{ NUM, OPS, STR, OPEN, CLOSE };
    
    std::string GetValue() const;
    size_t GetPos() const;
    Kind GetKind() const;
private:
    Kind FindKind(std::string a_value);
private:
    std::string m_value;
    size_t m_pos;
    Kind m_kind;    
};
bool isOprator(std::string a_str);
bool isClose(std::string a_str);
bool isOpen(std::string a_str);
bool isDigit(std::string a_str);

#endif
