#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Board.hpp"
#include "Ball.hpp"
#include "Bar.hpp"

namespace h72{

class Game
{
public:
    Game();
    ~Game() = default;

    void Run();
    void Restart();

private:
    sf::RenderWindow m_window;
    Board m_board;  
    Ball m_ball;  
    Bar m_bar;  
    bool m_flag;
};

}

#endif