#include <thread>
#include <random>
#include <semaphore>
#include "DoubleBuffer.hpp"
#include "GameOfLife.hpp"
#include "Pixel.hpp"
#include "Point.hpp"

namespace h72{

GameOfLife::GameOfLife(size_t a_width, size_t a_height)
: m_width(a_width)
, m_height(a_height)
, m_buffer(m_width, m_height)
{
    Pixel black(0,0,0);
    Pixel white(255,255,255);
    m_pixBlack = black;
    m_pixWhite = white;
    m_threads.reserve(m_numOfThread);
    m_buffer.Fill(Side::FRONT, m_pixWhite);
    CreateGame();
}

GameOfLife::~GameOfLife()
{
    for(auto& t : m_threads){
        t.join();
    }
}

void GameOfLife::Run()
{
    CreateThreads();
    for(size_t i = 2; i <= m_numOfFrame; ++i){
        WaitForThreads();
        m_buffer.SwitchSides();
        m_buffer.SaveToFile(std::to_string(m_numPic)+".ppm");
        ++m_numPic;
        m_canCompute.release(m_numOfThread);
    }
}

void GameOfLife::CreateGame()
{
    srand(time(NULL));
    for(size_t i = 0; i < 32000; ++i){
        size_t x = rand() % m_width;
        size_t y = rand() % m_height;
        m_buffer.DrawPixel(m_pixBlack, Point(x, y).GetIndx(m_width));
    }
    m_buffer.SaveToFile(std::to_string(m_numPic)+".ppm");
    ++m_numPic;
}


void GameOfLife::CreateThreads()
{
    size_t segment = m_height * m_width / m_numOfThread;
    size_t start = 0;
    size_t end = segment;
    
    for (size_t i = 0; i < m_numOfThread; ++i){
        std::thread t(&GameOfLife::CreateNextImage, this, start, end);
        m_threads.push_back(std::move(t));
        start += segment;
        end += segment;
    }
}

void GameOfLife::CreateNextImage(size_t a_start, size_t a_end)
{
    for(size_t j = 0; j < m_numOfFrame-1; ++j){
        for(size_t i = a_start; i < a_end; ++i){
            Point point((i % m_width), (i / m_width));
            unsigned int neighbors = NumOfNeighbor(point);
            if(m_buffer.GetPixel(i, Side::BACK) == m_pixBlack && (neighbors < 2 || neighbors > 3)){
                m_buffer.DrawPixel(m_pixWhite, i);
            }else if(m_buffer.GetPixel(i, Side::BACK) != m_pixBlack && neighbors == 3){
                m_buffer.DrawPixel(m_pixBlack, i);
            } else if(m_buffer.GetPixel(i, Side::BACK) == m_pixBlack && (neighbors == 3 || neighbors == 2)){
                m_buffer.DrawPixel(m_pixBlack, i);
            }else{
                m_buffer.DrawPixel(m_pixWhite, i);
            }
        }
        m_doneCompute.release();
        m_canCompute.acquire();
    }

}

unsigned int GameOfLife::NumOfNeighbor(Point const& a_point) const
{
    unsigned int neighbors = 0;
    for(int x = -1; x <= 1; ++x){
        for(int y = -1; y <= 1; ++y){
            if(x == 0 && y == 0){
                continue;
            }
            Point neighbor(a_point.GetX() + x, a_point.GetY() + y);
            size_t index = neighbor.GetIndx(m_width);
            if(index < m_width * m_height && m_buffer.GetPixel(index, Side::BACK) == m_pixBlack){
                ++neighbors;
            }
        }
    }
    return neighbors;
}

void GameOfLife::WaitForThreads() 
{
    for(size_t i = 0; i < m_numOfThread; ++i){
        m_doneCompute.acquire(); 
    }
}

}
