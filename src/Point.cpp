#include "Point.hpp"

namespace h72{

Point::Point(size_t a_x, size_t a_y) 
: m_x(a_x)
, m_y(a_y)
{
}

Point::Point(Point const& a_source)
: m_x(a_source.m_x)
, m_y(a_source.m_y)
{
}
    
Point& Point::operator=(Point const& a_source)
{
    m_x = a_source.m_x;
    m_y = a_source.m_y;
    return *this;
}

bool Point::operator==(Point const& that) const
{
    return true;
}

bool Point::operator!=(Point const& that) const
{
    return true;
}

size_t Point::GetX() const
{
    return m_x;
}

size_t Point::GetY() const
{
    return m_y;
}

size_t Point::GetIndx(size_t a_width) const
{
    return m_x + m_y * a_width;
}


}
