#include "mu_test.h"

#include <string>
#include <climits>

#include <iostream>

#include "Game.hpp"
#include "Board.hpp"
#include "Ball.hpp"
#include "Bar.hpp"

using namespace h72;

BEGIN_TEST(check)

    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    window.setFramerateLimit(120);

    Board board(500, 500,sf::Color::Blue); 
    Ball ball(10.f, sf::Color::White, sf::Vector2f((500/2)-10,455), sf::Vector2f(1,1)); 
    Bar bar(sf::Vector2f(80,15), sf::Color::Red, sf::Vector2f((500/2)-40,475), sf::Vector2f(1,1));

    bool flag = false;

	while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed){
                flag = !flag;
            }
                
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            flag = true;
        }
        
        if(ball.GetPosition().x < 0 || ball.GetPosition().x > 500-20){
            ball.SetPositionX(-1);
        }
        if(ball.GetPosition().y < 0){
            ball.SetPositionY(-1);
        }
        if(ball.GetPosition().y > 500){
            ball.Restart();
            bar.Restart();
            flag = false;
        }
    
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && bar.GetPosition().x >= 0){
            bar.Move(-1);
            if(!flag){
                ball.Move(-1,0); 
            }  
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && bar.GetPosition().x <= 500-80){
            bar.Move(1);
            if(!flag){
                ball.Move(1,0); 
            } 
        }
        if(ball.GetPosition().y == bar.GetPosition().y - 20 && ball.GetPosition().x + 20 >= bar.GetPosition().x &&  ball.GetPosition().x <= bar.GetPosition().x + 80 ){
            ball.SetPositionY(-1);
        }

        if(flag){
            ball.Move(1,1);
        }
       
        window.clear();
        window.draw(board.GetShape());
        window.draw(ball.GetShape());
        window.draw(bar.GetShape());
        window.display();
    }

	ASSERT_PASS();
END_TEST


BEGIN_TEST(checkGame)
    Game game;
    game.Run();

	ASSERT_PASS();
END_TEST

TEST_SUITE("זִיַאדַּתּ אַלגַּום, לַא כַיר פִיהּ")
    //TEST(check)
    TEST(checkGame)
	
END_SUITE

