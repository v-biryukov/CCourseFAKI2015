#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <cmath>

#include "arkanoid_basics.h"


int main () 
{
    Ball ball = Ball(window_width / 2, window_height / 2 );
    Paddle paddle = Paddle(window_width / 2, window_height - 50);

    std::vector<Brick> bricks;

    for(int i = 0; i < 11; ++i)
        for(int j = 0; j < 10; ++j) 
            bricks.push_back(Brick((i + 1) * (block_width + 3) +22, (j + 2) * (block_height +3)));
        

    sf::RenderWindow window(sf::VideoMode(window_width, window_height, 32), "Arkanoid");
    window.setFramerateLimit(60);

    while (window.isOpen()) 
    {
        sf::Event event;
        while(window.pollEvent(event)) 
        {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
            {
                window.close();
            }
            if (ball.y() > window_height + ball_radius)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseMoved)
            {
                paddle.setX(event.mouseMove.x);
            }

        }

        window.clear(sf::Color::Black);
        ball.update();
        paddle.update();

        testCollision(paddle, ball);


        for(int i = 0; i < bricks.size(); ++i) 
            testCollision(bricks[i], ball);


        sf::Font font;
        font.loadFromFile("arial.ttf");
        sf::Text text;
        text.setFont(font);
        text.setString("Arkanoid");
        text.setCharacterSize(24);
        text.setColor(sf::Color::White);
        text.setStyle(sf::Text::Bold);

        window.draw(text);

        window.draw(ball.shape);
        window.draw(paddle.shape);

        for(int i = 0; i < bricks.size(); ++i)
            window.draw(bricks[i].shape);

        window.display();

        for (std::vector<Brick>::iterator it = bricks.begin(); it != bricks.end(); )
        {
            if (it->destroyed)
                bricks.erase(it);
            else
                it++;
        }

    }

    return EXIT_SUCCESS;
}