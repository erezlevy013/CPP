#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>

class Rational
{
public:
    enum Indx
    {
        Numerator,
        Denom
    };

    Rational(); /* def ctor*/ 
    explicit Rational(int a_numer, int a_denom = 1); /*ctor*/ 
    Rational(const Rational& a_rational); /*copy ctor*/
    ~Rational() = default; /*dtor*/

    Rational& operator=(const Rational& a_rational);
    Rational& operator*=(int a_rval);
    Rational& operator*=(const Rational& a_rational);
    Rational& operator+=(int a_rval);
    Rational& operator+=(const Rational& a_rational);
    Rational& operator-=(int a_rval);
    Rational& operator-=(const Rational& a_rational);
    Rational& operator/=(int a_rval);
    Rational& operator/=(const Rational& a_rational);
    Rational& Reduce();

    int getNumer() const;
    int getDenom() const;
    int operator[](Indx a_indx) const;
    double operator()() const;
    void Print() const; 

private:
    int m_numer = 1;
    int m_denom = 1; 
};

Rational operator*(Rational a_rational , int a_rval); 
Rational operator*(int a_lval, Rational a_rational); 
Rational operator*(Rational a_rationalOne , Rational a_rationalTwo);

Rational operator+(Rational a_rational , int a_rval); 
Rational operator+(int a_lval, Rational a_rational); 
Rational operator+(Rational a_rationalOne , Rational a_rationalTwo);

Rational operator-(Rational a_rational , int a_rval); 
Rational operator-(int a_lval, Rational a_rational); 
Rational operator-(Rational a_rationalOne , Rational a_rationalTwo);

Rational operator/(Rational a_rational , int a_rval); 
Rational operator/(int a_lval, Rational a_rational); 
Rational operator/(Rational a_rationalOne , Rational a_rationalTwo);

bool operator>(Rational a_rationalOne , Rational a_rationalTwo);
bool operator<(Rational a_rationalOne , Rational a_rationalTwo);

bool operator==(Rational a_rationalOne , Rational a_rationalTwo);
bool operator!=(Rational a_rationalOne , Rational a_rationalTwo);

std::ostream& operator<<(std::ostream& a_os, Rational a_rational);

int Gcd(int a_first, int a_second);

#endif /* RATIONAL_HPP */
