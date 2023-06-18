#include "Line.hpp"
#include "DoubleBuffer.hpp"
#include "Point.hpp"
#include "MyException.hpp"

namespace h72{

template<typename T>
Line<T>::Line(Point const& a_start, Point const& a_end, T a_pixel)
: m_start(a_start)
, m_end(a_end)
, m_pixel(a_pixel)
{
}

template<typename T>
void Line<T>::Draw(DoubleBuffer<T>& a_db) const
{
    if(m_end.GetX() > a_db.GetWidth() || m_end.GetY() > a_db.GetHeight()){
        throw MyException("out of range");
    }

    if(m_start.GetX() == m_end.GetX()){
        DrawCol(a_db, a_db.GetWidth());
    } else if(m_start.GetY() == m_end.GetY()){
        DrawRow(a_db, a_db.GetWidth());
    } else {
        if(m_end.GetX() - m_start.GetX() == m_end.GetY() - m_start.GetY()){
            DrawDiagonalLeft(a_db, a_db.GetWidth());
        } 
        else if(m_end.GetX() - m_start.GetX() == (m_end.GetY() - m_start.GetY()) * (-1)){
            DrawDiagonalRight(a_db, a_db.GetWidth());
        }
    }
}

template<typename T>
void Line<T>::DrawRow(DoubleBuffer<T>& a_buffer, size_t a_width) const
{
    size_t min = m_start.GetIndx(a_width);
    size_t max = m_end.GetIndx(a_width);
    for(size_t i = min; i < max; ++i){
        a_buffer.DrawPixel(m_pixel, i);
    }
}

template<typename T>
void Line<T>::DrawCol(DoubleBuffer<T>& a_buffer, size_t a_width) const
{
    size_t min = m_start.GetIndx(a_width);
    size_t max = m_end.GetIndx(a_width);
    for(size_t i = min; i <= max; i+= a_width){
        a_buffer.DrawPixel(m_pixel, i);
    }
}

template<typename T>
void Line<T>::DrawDiagonalLeft(DoubleBuffer<T>& a_buffer, size_t a_width) const
{
    
    size_t min = m_start.GetIndx(a_width);
    size_t max = m_end.GetIndx(a_width);
    for(size_t i = min; i < max; i+= (a_width + 1)){
        a_buffer.DrawPixel(m_pixel, i);
    }
}

template<typename T>
void Line<T>::DrawDiagonalRight(DoubleBuffer<T>& a_buffer, size_t a_width) const
{
    size_t max = m_start.GetIndx(a_width) - 1;
        size_t min = m_end.GetIndx(a_width) - 1;
        for(size_t i = min; i < max; i+= (a_width - 1)){
            a_buffer.DrawPixel(m_pixel, i);
        }
}

}