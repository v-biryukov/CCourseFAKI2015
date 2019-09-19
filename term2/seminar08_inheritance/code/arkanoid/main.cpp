#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

#include "arkanoid.h"

int main () 
{
    // Создаём экземпляры класса шарик и ракетка
    Ball ball = Ball(window_width / 2, window_height / 2 );
    Paddle paddle = Paddle(window_width / 2, window_height - 50);

    // Создаём вектор из блоков
    std::vector<Brick> bricks;
    for(int i = 0; i < 11; ++i)
        for(int j = 0; j < 5; ++j) 
            bricks.push_back(Brick((i + 1) * (block_width + 3) + 22, (j + 2) * (block_height +3)));
        

    // Окно
    sf::RenderWindow window(sf::VideoMode(window_width, window_height, 32), "Arkanoid");
    window.setFramerateLimit(60);
    while (window.isOpen()) 
    {
        // Обработка событий
        sf::Event event;
        while(window.pollEvent(event)) 
        {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
            {
                window.close();
            }
            // Если шарик упал, то выходим из игры
            if (ball.y() > window_height + ball_radius)
            {
                //window.close();
            }
            // Двигаем ракетку
            if (event.type == sf::Event::MouseMoved)
            {
                paddle.setX(event.mouseMove.x);
            }

        }
        // Очищаем окно черным цветом
        window.clear(sf::Color::Black);
        // Расчитываем новые координаты и новую скорость шарика
        ball.update();
        // Проверяем сталкивается ли шарик с ракеткой или блоками и если сталкивется
        //     то устанавливаем новые координаты и новую скорость шарика
        testCollision(paddle, ball);
        for(int i = 0; i < bricks.size(); ++i) 
            testCollision(bricks[i], ball);


        // Пишем Arkanoid вверху экрана
        sf::Font font;
        font.loadFromFile("arial.ttf");
        sf::Text text;
        text.setFont(font);
        text.setString("Arkanoid");
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setStyle(sf::Text::Bold);
        window.draw(text);

        // Рисуем шарик, ракетку и блоки
        // Рисование происходит на временом "холсте"
        window.draw(ball.shape);
        window.draw(paddle.shape);
        for(int i = 0; i < bricks.size(); ++i)
            window.draw(bricks[i].shape);

        // Отображам всё нарисованное на временном "холсте" на экран
        window.display();

        // Удаляем все блоки, которые были уничтожены
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
