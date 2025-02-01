#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Draggable
{
private:
    sf::RectangleShape mShape   {};
    bool mIsDragged             {false};
    sf::Vector2f mOffset        {0.0f, 0.0f};

public:
    Draggable() {};
    Draggable(const sf::RectangleShape& shape) : mShape{shape} {}
    Draggable(sf::Vector2f position, sf::Vector2f size, sf::Color color) 
    {
        mShape.setPosition(position);
        mShape.setSize(size);
        mShape.setFillColor(color);
    }

    bool onMousePressed(sf::Vector2f mousePosition)
    {
        if (mShape.getGlobalBounds().contains(mousePosition))
        {
            mIsDragged = true;
            mOffset = mousePosition - mShape.getPosition();
        }
        return mIsDragged;
    }

    void onMouseReleased()
    {
        mIsDragged = false;
    }

    void onMouseMoved(sf::Vector2f mousePosition)
    {
        if (mIsDragged)
        {
            mShape.setPosition(mousePosition - mOffset);
        }
    }

    void setColor(sf::Color c)
    {
        mShape.setFillColor(c);
    }

    void setSize(sf::Vector2f sz)
    {
        mShape.setSize(sz);
    }

    void setPosition(sf::Vector2f p)
    {
        mShape.setPosition(p);
    }

    void draw(sf::RenderWindow& rw) const
    {
        rw.draw(mShape);
    }
};



int main()
{
    std::srand(std::time(nullptr));

    const int width = 800;
    const int height = 600;

    sf::RenderWindow window(sf::VideoMode(width, height), "Cards");
    window.setFramerateLimit(60);


    std::vector<Draggable> draggables;
    for (int i = 0; i < 20; ++i)
    {
        int randomWidth = 10 + rand() % (width / 3);
        int randomHeight = 10 + rand() % (height / 3);
        int randomX = rand() % (width - randomWidth);
        int randomY = rand() % (height - randomHeight);
        sf::Color randomColor {(unsigned char)rand(), (unsigned char)rand(), (unsigned char)rand()};
        draggables.push_back({{(float)randomX, (float)randomY}, {(float)randomWidth, (float)randomHeight}, randomColor});
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});

                for (auto& d : draggables)
                {
                    if (d.onMousePressed(mousePosition))
                        break;
                }
            }

            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
                for (auto& d : draggables)
                {
                    d.onMouseReleased();
                }
            }

            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
                for (auto& d : draggables)
                {
                    d.onMouseMoved(mousePosition);
                }
                
            }
        }
        
        window.clear(sf::Color::Black);
        for (auto it = draggables.crbegin(); it != draggables.crend(); ++it)
        {
            it->draw(window);
        }
        
        window.display();
    }
}