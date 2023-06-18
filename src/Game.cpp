#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Board.hpp"
#include "Ball.hpp"
#include "Bar.hpp"

namespace h72{

Game::Game()
: m_window(sf::VideoMode(500, 500), "Game!!!")
, m_board(500, 500,sf::Color::Blue)
, m_ball(10.f, sf::Color::White, sf::Vector2f((500/2)-10,455), sf::Vector2f(1,1))
, m_bar(sf::Vector2f(80,15), sf::Color::Red, sf::Vector2f((500/2)-40,475), sf::Vector2f(1,1))
, m_flag(false)
{
    m_window.setFramerateLimit(120);
}

void Game::Run()
{
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                m_window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed){
                m_flag = !m_flag;
            }
                
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            m_flag = true;
        }
        
        if(m_ball.GetPosition().x < 0 || m_ball.GetPosition().x > 500-20){
            m_ball.SetPositionX(-1);
        }
        if(m_ball.GetPosition().y < 0){
            m_ball.SetPositionY(-1);
        }
        if(m_ball.GetPosition().y > 500){
            m_ball.Restart();
            m_bar.Restart();
            m_flag = false;
        }
    
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_bar.GetPosition().x >= 0){
            m_bar.Move(-1);
            if(!m_flag){
                m_ball.Move(-1,0); 
            }  
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_bar.GetPosition().x <= 500-80){
            m_bar.Move(1);
            if(!m_flag){
                m_ball.Move(1,0); 
            } 
        }
        if(m_ball.GetPosition().y == m_bar.GetPosition().y - 20 && m_ball.GetPosition().x + 20 >= m_bar.GetPosition().x &&  m_ball.GetPosition().x <= m_bar.GetPosition().x + 80 ){
            m_ball.SetPositionY(-1);
        }

        if(m_flag){   
            m_ball.Move(1,1);
        }
       
        m_window.clear();
        m_window.draw(m_board.GetShape());
        m_window.draw(m_ball.GetShape());
        m_window.draw(m_bar.GetShape());
        m_window.display();
    }
}

void Game::Restart()
{
    
}


}
