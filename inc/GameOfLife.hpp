#ifndef GAME_OF_LIFE_HPP
#define GAME_OF_LIFE_HPP

#include <thread>
#include <string>
#include <vector>
#include <semaphore>
#include "Pixel.hpp"
#include "Point.hpp"
#include "DoubleBuffer.hpp"

namespace h72{

class GameOfLife
{
public:
    explicit GameOfLife(size_t a_width, size_t a_height);
    ~GameOfLife();

    void Run();

private:    
    void CreateGame();
    void CreateThreads();
    void CreateNextImage(size_t a_start, size_t a_end);
    unsigned int NumOfNeighbor(Point const& a_point) const;
    void WaitForThreads();

private:
    size_t m_width;
    size_t m_height;
    size_t m_numPic = 1;
    size_t const m_numOfFrame = 10;
    size_t const m_numOfThread = 4;
    Pixel m_pixBlack;
    Pixel m_pixWhite;
    DoubleBuffer<Pixel> m_buffer;
    std::vector<std::thread> m_threads;
    std::counting_semaphore<4> m_canCompute{0};
    std::counting_semaphore<4> m_doneCompute{4};
};

}

#endif
