#include <ostream>
#include <string>
#include <ostream>
#include "Pixel.hpp"

namespace h72{

Pixel::Pixel(unsigned int a_red, unsigned int a_green, unsigned int a_blue) 
: m_red(a_red)
, m_green(a_green)
, m_blue(a_blue)
{
}

Pixel::Pixel(Pixel const& a_pixel)
: m_red(a_pixel.m_red)
, m_green(a_pixel.m_green)
, m_blue(a_pixel.m_blue)
{

}

bool Pixel::operator==(Pixel const &a_pixel) const
{
    if (m_red == a_pixel.m_red && m_blue == a_pixel.m_blue && m_green == a_pixel.m_green){
        return true;
    }
    return false;
}

bool Pixel::operator!=(Pixel const& a_pixel) const
{
    return !(*this == a_pixel);
}

unsigned int Pixel::GetRed() const
{
    return m_red;
}

unsigned int Pixel::GetGreen() const
{
    return m_green;
}

unsigned int Pixel::GetBlue() const
{
    return m_blue;
}

std::ostream& Pixel::Print(std::ostream& a_out) const
{
    a_out << m_red << " " << m_green <<" "<< m_red;
    return a_out;
}

std::string Pixel::PixelToStr()
{
    std::string str = std::to_string(m_red) + " " + std::to_string(m_green) + " " + std::to_string(m_blue);
    return str;
}


std::ostream& operator<<(std::ostream& a_out, const Pixel& a_pixel)
{
    return a_pixel.Print(a_out);
}


}

