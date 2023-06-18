#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "DoubleBuffer.hpp"

namespace h72{

template<typename T>
class Shape
{
public:
    virtual ~Shape() = default;
    virtual void Draw(DoubleBuffer<T>& a_db) const = 0;
};


}

#endif