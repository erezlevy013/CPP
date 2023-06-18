#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <cassert>
#include <string>
#include <cmath>


#include "../DoubleBuffer.hpp"
#include "../Point.hpp"
#include "../Pixel.hpp"

namespace h72{

template<typename T>
DoubleBuffer<T>::DoubleBuffer(size_t a_width , size_t a_height)
: m_width(a_width)
, m_height(a_height)
, m_front(new T[m_width * m_height])
{
    try{
        m_back = new T[m_width * m_height];
    }catch(std::bad_alloc const &e){
        delete[] m_front;
        //throw NomemoryForBufferException(m_width* m_height, "....");
    }
}

template<typename T>
DoubleBuffer<T>::DoubleBuffer(DoubleBuffer<T> const& a_source)
: m_width(a_source.m_width)
, m_height(a_source.m_height)
, m_front(new T[m_width * m_height])
{
    size_t size = m_width * m_height;
    try{
        m_back = new T[size];

        std::copy(a_source.m_front, a_source.m_front + size, m_front);
        std::copy(a_source.m_back, a_source.m_back + size, m_back);
    }catch(std::bad_alloc const &e){
        delete[] m_front;
        //throw xxx;
    }
}

template<typename T>
DoubleBuffer<T>::~DoubleBuffer()
{
    delete[] m_front;
    delete[] m_back;
}

template<typename T>
DoubleBuffer<T>& DoubleBuffer<T>::operator=(DoubleBuffer<T> const& a_source)
{
    if(this == &a_source){
        return *this;
    }

    size_t size = a_source.m_width * a_source.m_height;
    auto newFront = new T[size];
    try{
        auto newBack = new T[size];
        m_width = a_source.m_width;
        m_height = a_source.m_height;

        std::copy(a_source.m_front, a_source.m_front + size, newFront);
        std::copy(a_source.m_back, a_source.m_back + size, newBack);

        delete[] m_front;
        delete[] m_back;

        m_front = newFront;
        m_back = newBack;
    }catch(std::bad_alloc const &e){
        delete[] newFront;
        //throw
        //std::cout<<e.what()<< std::endl;
    }

    return *this;
}

template<typename T>
size_t DoubleBuffer<T>::GetWidth() const
{
    return m_width;
}

template<typename T>    
size_t DoubleBuffer<T>::GetHeight() const
{
    return m_height;
}

template<typename T>  
Pixel DoubleBuffer<T>::GetPixel(size_t a_indx, Side a_side) const
{
    if(a_side == Side::FRONT){
        return m_front[a_indx];
    }
    return m_back[a_indx];
}

template<typename T>
void DoubleBuffer<T>::Fill(Side a_side, T a_value)
{
    if(a_side == Side::FRONT){
        std::fill_n(m_front, m_width*m_height, a_value);
    }else{
        std::fill_n(m_front, m_width*m_height, a_value);
    }
    std::cout<<m_front[0] <<" "<<m_front[1]<<"\n";
}

template<typename T>
void DoubleBuffer<T>::Clear(Side a_side)
{
    Fill(a_side, T{});
}

template<typename T>
void DoubleBuffer<T>::SwitchSides()
{
    std::swap(m_front, m_back);
}

template <typename T>
void DoubleBuffer<T>::DrawPixel(Pixel a_pixel, size_t const& i)
{   
    if(i > m_height*m_width){
       throw; 
    }
    m_front[i] = a_pixel;
}

// template <typename T>
// void DoubleBuffer<T>::SaveToFile(char* a_name) const
// {
//         std::cout<<m_front[0] <<" "<<m_front[1]<<"\n";
//         try{
//             FILE* fp = fopen(a_name, "w");
//             fprintf(fp, "%s\n", "P3");
//             fprintf(fp, "%d %d\n255\n", static_cast<int>(m_width),static_cast<int>(m_height));
//             for(size_t i = 0; i < m_width*m_height; ++i){
//                 fprintf(fp, "%d ", m_front[i].GetRed());
//                 fprintf(fp, "%d ", m_front[i].GetGreen());
//                 fprintf(fp, "%d\n", m_front[i].GetBlue());
//             }
//             fclose(fp);

//         }catch(std::ostream const& e){
//             throw;
//         }
// }

template <typename T>
void DoubleBuffer<T>::SaveToFile(std::string a_filaName)
{
    try
    {
        std::ofstream file("frame."+a_filaName);
        file << "P3\n"  << m_width << " " << m_height << "\n" << "255\n";
        for (size_t i = 0; i < m_width * m_height; i++)
        {
            file << m_front[i].PixelToStr() << "\n";
        }
        if (file.bad()){
            throw; //myException("file was not opened");
        }
        file.close();
    }
    catch (std::ifstream::failure const &e){
        throw; //myException("file failed ");
    }
}


template <typename T>
std::ostream& DoubleBuffer<T>::Print(std::ostream &os, Side a_side) const
{
    if (a_side == Side::FRONT){
        std::cout << m_width * m_height << std::endl;
        for (size_t i = 0; i < (m_width * m_height); i++)
        {
            if(i > 0 && i%(m_width) == 0)
            {
               os <<"\n";
            }
            os << m_front[i] << " ";

        }
        os << "\n";
    }else{
        for (size_t i = 0; i < (m_width * m_height); i++)
        {
            os << m_back[i] << " ";
        }
        os << "\n";
    }
    return os;
}

}
