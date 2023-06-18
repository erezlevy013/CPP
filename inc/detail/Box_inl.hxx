#include "Box.hpp"
#include "DoubleBuffer.hpp"
#include "Shape.hpp"
#include "Point.hpp"
#include "MyException.hpp"
#include "Line.hpp"

namespace h72{

template<typename T>
Box<T>::Box(Point a_topLeft, Point a_bottomRight, T a_color)
: m_topLeft(a_topLeft)
, m_bottomRight(a_bottomRight)
, m_color(a_color)
{
}

template<typename T>
void Box<T>::Draw(DoubleBuffer<T>& a_doubleBuffer) const
{
    if(m_topLeft.GetX() > a_doubleBuffer.GetWidth() || m_bottomRight.GetY() > a_doubleBuffer.GetHeight()){
        throw MyException("Box is out of buffer's bound");
    }
    else if(m_topLeft.GetX() >= m_bottomRight.GetX() || m_topLeft.GetY() >= m_bottomRight.GetY()){
        throw MyException("Given box is not a square!");
    }
    Point topRight(m_bottomRight.GetX(), m_topLeft.GetY());
    Point bottomLeft(m_topLeft.GetX(), m_bottomRight.GetY());
    Line<T> topLine(m_topLeft, topRight, m_color);
    topLine.Draw(a_doubleBuffer);
    Line<T> leftSideLine(m_topLeft, bottomLeft, m_color);
    leftSideLine.Draw(a_doubleBuffer);   
    Line<T> rightSideLine(topRight, m_bottomRight, m_color);
    rightSideLine.Draw(a_doubleBuffer);
    Line<T> bottomLine(bottomLeft, m_bottomRight, m_color);
    bottomLine.Draw(a_doubleBuffer);
}

}

