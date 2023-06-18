#ifndef PIXEL_HPP
#define PIXEL_HPP

#include "Point.hpp"

namespace h72{

class Pixel
{
public:
    Pixel() = default;
    Pixel(Pixel const& a_pixel);
    Pixel(unsigned int a_red, unsigned int a_green, unsigned int a_blue);

    unsigned int GetRed() const;
    unsigned int GetGreen() const;
    unsigned int GetBlue() const;

    // void DrawPixel(Point const& a_p);
    bool operator==(Pixel const& a_pixel) const;
    bool operator!=(Pixel const& a_pixel) const;
    std::ostream& Print(std::ostream& a_out) const;
    std::string PixelToStr();

private:
    unsigned int m_red = 0;
    unsigned int m_green = 0;
    unsigned int m_blue = 0;
};

std::ostream& operator<<(std::ostream& a_out, const Pixel& a_pixel);

}

#endif
