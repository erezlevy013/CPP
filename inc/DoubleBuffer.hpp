#ifndef DOUBLE_BUFFER_HPP
#define DOUBLE_BUFFER_HPP

#include "Point.hpp"
#include "Pixel.hpp"

namespace h72{

enum Side{FRONT, BACK};

template<typename T>
class DoubleBuffer
{
public:
    explicit DoubleBuffer(size_t a_width , size_t a_height);
    DoubleBuffer(DoubleBuffer<T> const& a_source);
    ~DoubleBuffer();
    DoubleBuffer<T>& operator=(DoubleBuffer<T> const& a_source);

    size_t GetWidth() const;
    size_t GetHeight() const;
    Pixel GetPixel(size_t a_indx, Side a_side) const; 
  
    void Fill(Side a_side, T a_value);
    void Clear(Side a_side);
    void SwitchSides();
    
    //void SaveToFile(char* a_name) const;
    void SaveToFile(std::string a_filaName);
    void DrawPixel(Pixel a_pixel, size_t const& i);
    std::ostream& Print(std::ostream &os, Side a_side) const;


private:
    size_t m_width;
    size_t m_height;
    T* m_front;
    T* m_back;
};

}

#include "detail/DoubleBuffer_inl.hxx"

#endif
