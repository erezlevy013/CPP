#ifndef BOX_HPP
#define BOX_HPP

#include <cstddef> 

#include "DoubleBuffer.hpp"
#include "Shape.hpp"
#include "Point.hpp"

namespace h72{

template<typename T>
class Box : public Shape<T>
{
public:
    explicit Box(Point a_topLeft, Point a_bottomRight, T a_color);
    ~Box() = default;

    void Draw(DoubleBuffer<T>& a_doubleBuffer) const;

private:
    Point m_topLeft;
    Point m_bottomRight;
    T m_color;
};

}

#include "detail/Box_inl.hxx"

#endif 
