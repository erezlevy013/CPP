#include <cassert>
#include <iostream>

#include "rational.hpp"

Rational::Rational()
{

}
 
Rational::Rational(const Rational& a_rational)
: m_numer(a_rational.getNumer())
, m_denom(a_rational.getDenom())
{

}

Rational::Rational(int a_numer, int a_denom)
: m_numer(a_numer)
, m_denom(a_denom)
{
    assert(a_denom != 0);
    if(m_denom < 0){
        m_numer *= -1;
        m_denom *= -1;
    }
}

int Rational::getNumer() const
{
    return m_numer;
}

int Rational::getDenom() const
{
    return m_denom;
}

void Rational::Print() const
{
    std::cout << m_numer << ", " << m_denom << '\n';  
}

Rational& Rational::operator=(const Rational& a_rational)  
{
    m_numer = a_rational.getNumer();
    m_denom = a_rational.getDenom();  
    return *this;
}

Rational& Rational::operator*=(int a_rval)
{
    *this = *this * a_rval;
    return *this;
}

Rational& Rational::operator*=(const Rational& a_rational)
{
    *this = *this * a_rational;
    return *this;
}

Rational& Rational::operator+=(int a_rval)
{
    *this = *this + a_rval;
    return *this;
}

Rational& Rational::operator+=(const Rational& a_rational)
{
    *this = *this + a_rational;
    return *this;
}

Rational& Rational::operator-=(int a_rval)
{
    *this = *this - a_rval;
    return *this;
}

Rational& Rational::operator-=(const Rational& a_rational)
{
    *this = *this - a_rational;
    return *this;
}

Rational& Rational::operator/=(int a_rval)
{
    *this = *this / a_rval;
    return *this;
}

Rational& Rational::operator/=(const Rational& a_rational)
{
    *this = *this / a_rational;
    return *this;
}

int Rational::operator[](Indx a_rval) const
{
    if(a_rval == Rational::Numerator){
        return m_numer;
    }
    return m_denom;
}

double Rational::operator()() const
{
    return static_cast<double>(m_numer)/m_denom; 
}

Rational& Rational::Reduce()
{
    int num = Gcd(m_numer, m_denom);
    m_numer = m_numer/num;
    m_denom = m_denom/num;
    return *this;
}

Rational operator*(Rational a_rational , int rval)  //&
{
    Rational t(a_rational.getNumer() * rval, a_rational.getDenom());
    return t;
}

Rational operator*(int a_lval, Rational a_rational)
{
    return a_rational * a_lval;
}

Rational operator*(Rational a_rationalOne , Rational a_rationalTwo)  //&  
{
    int numer = a_rationalOne.getNumer() * a_rationalTwo.getNumer();
    int denom = a_rationalOne.getDenom() * a_rationalTwo.getDenom();
    return Rational(numer, denom).Reduce();
}

Rational operator+(Rational a_rational , int a_rval)  
{
    int numer = a_rational.getNumer() + a_rval * a_rational.getDenom();
    int denom = a_rational.getDenom();
    return Rational(numer, denom).Reduce();
}

Rational operator+(int a_lval, Rational a_rational)  
{
    return a_rational + a_lval;
}

Rational operator+(Rational a_rationalOne , Rational a_rationalTwo) 
{
    int numer = a_rationalOne.getNumer() * a_rationalTwo.getDenom() + a_rationalOne.getDenom() * a_rationalTwo.getNumer();
    int denom = a_rationalOne.getDenom() * a_rationalTwo.getDenom();
    return Rational(numer, denom).Reduce();
}

Rational operator-(Rational a_rational , int a_rval) 
{
    int numer = a_rational.getNumer() - a_rval * a_rational.getDenom();
    int denom = a_rational.getDenom();
    return Rational(numer, denom).Reduce();
}

Rational operator-(int a_lval, Rational a_rational)  
{
    return Rational(a_lval) - a_rational;
}

Rational operator-(Rational a_rationalOne , Rational a_rationalTwo) 
{
    int numer = a_rationalOne.getNumer() * a_rationalTwo.getDenom() - a_rationalOne.getDenom() * a_rationalTwo.getNumer();
    int denom = a_rationalOne.getDenom() * a_rationalTwo.getDenom();
    return Rational(numer, denom).Reduce();
}

Rational operator/(Rational a_rational , int a_rval)   
{
    return Rational(a_rational.getNumer(), a_rational.getDenom() * a_rval).Reduce();
}

Rational operator/(int a_lval, Rational a_rational)
{
    return  Rational(a_lval) / a_rational;
}

Rational operator/(Rational a_rationalOne , Rational a_rationalTwo) 
{
    int numer = a_rationalOne.getNumer() * a_rationalTwo.getDenom();
    int denom = a_rationalOne.getDenom() * a_rationalTwo.getNumer();
    return Rational(numer, denom).Reduce();
}

bool operator>(Rational a_rationalOne , Rational a_rationalTwo)
{
    int first = a_rationalOne.getNumer() * a_rationalTwo.getDenom();
    int second = a_rationalTwo.getNumer() * a_rationalOne.getDenom();
    return (first - second) > 0;
}

bool operator<(Rational a_rationalOne , Rational a_rationalTwo)
{
    int first = a_rationalOne.getNumer() * a_rationalTwo.getDenom();
    int second = a_rationalTwo.getNumer() * a_rationalOne.getDenom();
    return (first - second) < 0;
}

bool operator==(Rational a_rationalOne , Rational a_rationalTwo)  
{
    return (a_rationalOne.getNumer() == a_rationalTwo.getNumer()) && (a_rationalOne.getDenom() == a_rationalTwo.getDenom());
}

bool operator!=(Rational a_rationalOne , Rational a_rationalTwo)  
{
    return !(a_rationalOne == a_rationalTwo);
}

std::ostream& operator<<(std::ostream& a_out, Rational a_rational)
{
    a_out << a_rational.getNumer() << "/" << a_rational.getDenom() << std::endl;;
    return a_out;
}

int Gcd(int a_first, int a_second)
{
    if(a_first < 0){
        a_first *= -1;
    }
    if(a_second < 0){
        a_second *= -1;
    }
    int remainder = 1;
    while(remainder){
        if(a_second > a_first){
            int temp = a_first; 
            a_first = a_second;
            a_second = temp;
        }
        remainder = a_first % a_second;
        a_first = a_second;
        a_second = remainder;
    }
    return a_first;
}
