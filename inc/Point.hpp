#ifndef POINT_HPP
#define POINT_HPP

#include <cstddef>

namespace h72{

class Point
{
public:
    Point() = default;
    Point(size_t a_x, size_t a_y); 
    Point(Point const& a_source);
    ~Point() = default;
    Point& operator=(Point const& a_source);

    bool operator==(Point const& that) const;
    bool operator!=(Point const& that) const;

    size_t GetX()const;
    size_t GetY()const;
    size_t GetIndx(size_t a_width)const;

private:
    size_t m_x = 1;
    size_t m_y = 1;
};

}

#endif
