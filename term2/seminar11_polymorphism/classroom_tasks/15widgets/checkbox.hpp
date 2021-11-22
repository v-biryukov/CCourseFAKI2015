#pragma once

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


// Класс флажка
class Checkbox
{
private:
    // Статические константы, общие для всех флажков
    inline static const int boundarySize = 24;
    inline static const int outerSize = 16;
    inline static const int innerSize = 10;

    inline static const sf::Color outerColor {sf::Color::White};
    inline static const sf::Color innerColor {sf::Color::Black};
    inline static const sf::Color textColor {sf::Color::White};

    sf::RenderWindow* mpSFMLWindow;

    // Внешний квадратик
    sf::RectangleShape outerShape;
    // Внутрений квадратик
    sf::RectangleShape innerShape;
    sf::Text text;

    bool isActivated;

public:
    Checkbox(sf::RenderWindow* window, int x, int y, const sf::Font& font, const sf::String& textData) 
            : mpSFMLWindow(window)
    {
        text.setFont(font);
        text.setString(textData);
        text.setCharacterSize(24);
        text.setFillColor(textColor);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setPosition(x + boundarySize, y + boundarySize/2 - textRect.height);

        outerShape.setPosition(x + boundarySize/2 - outerSize/2, y + boundarySize/2 - outerSize/2);
        outerShape.setSize(sf::Vector2f(outerSize, outerSize));
        outerShape.setFillColor(outerColor);

        innerShape.setPosition(x + boundarySize/2 - innerSize/2, y + boundarySize/2 - innerSize/2);
        innerShape.setSize(sf::Vector2f(innerSize, innerSize));
        innerShape.setFillColor(innerColor);

        isActivated = false;
        text.setFont(font);
    }

    bool getIsActivated() const
    {
        return isActivated;
    }

    std::string getTitle() const
    {
        return text.getString();
    }

    void draw(sf::RenderWindow& window) const
    {
        window.draw(text);
        window.draw(outerShape);
        if (isActivated) {
            window.draw(innerShape);
        }
    }

    bool checkCollision(int x, int y)
    {
        return (x > outerShape.getPosition().x && 
                x < outerShape.getPosition().x + outerShape.getSize().x &&
                y > outerShape.getPosition().y &&
                y < outerShape.getPosition().y + outerShape.getSize().y);
    }

    void onMousePressed(const sf::Event& event)
    {
        sf::Vector2f worldPos = mpSFMLWindow->mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (checkCollision(worldPos.x, worldPos.y)) {
                isActivated = !isActivated;
            }
        }
    }

    void onMouseReleased(const sf::Event& event)
    {
    }

    void onMouseMove(const sf::Event& event)
    {
    } 

    void handleEvent(const sf::Event& event)
    {
        if (event.type == sf::Event::MouseMoved) {
            onMouseMove(event);
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            onMousePressed(event);
        }
        else if (event.type == sf::Event::MouseButtonReleased) {
            onMouseReleased(event);
        }
    }
};
