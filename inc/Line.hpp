#ifndef LINE_HPP
#define LINE_HPP

#include "Point.hpp"
namespace h72{

template<typename T>
class Line : public Shape<T>
{
public:
    Line() = default;
    Line(Point const& a_start, Point const& a_end, T a_pixel);

    void Draw(DoubleBuffer<T>& a_db) const;
private:
    void DrawRow(DoubleBuffer<T>& a_buffer, size_t a_width) const;
    void DrawCol(DoubleBuffer<T>& a_buffer, size_t a_width) const;
    void DrawDiagonalLeft(DoubleBuffer<T>& a_buffer, size_t a_width) const;
    void DrawDiagonalRight(DoubleBuffer<T>& a_buffer, size_t a_width) const;
private:
    Point m_start;
    Point m_end;
    T m_pixel;
};

}

#include "detail/Line_inl.hxx"

#endif