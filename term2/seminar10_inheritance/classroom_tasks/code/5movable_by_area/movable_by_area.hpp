#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "movable.hpp"

class MovableByArea : public Movable
{
private:
    sf::FloatRect drawableRect;
    sf::Color drawableColor {150, 150, 150};

    sf::Vector2f drawableOffset;

public:

    MovableByArea(sf::RenderWindow& sfmlWindow, sf::FloatRect drawableRect, sf::FloatRect dragRect) :
            Movable(sfmlWindow, dragRect), drawableRect(drawableRect)
    {
        drawableOffset = sf::Vector2f{dragRect.left, dragRect.top} - sf::Vector2f{drawableRect.left, drawableRect.top};
    }

    void setDrawableColor(sf::Color newDrawableColor) {
        drawableColor = newDrawableColor;
    }

    sf::Color getDrawableColor() {
        return drawableColor;
    }

    void onMouseMoved(const sf::Event& event)
    {
        Movable::onMouseMoved(event);
        drawableRect.left = rect.left - drawableOffset.x;
        drawableRect.top = rect.top - drawableOffset.y;
    }



    void draw() {
        shape.setPosition({drawableRect.left, drawableRect.top});
        shape.setSize({drawableRect.width, drawableRect.height});
        shape.setFillColor(drawableColor);
        sfmlWindow.draw(shape);

        Movable::draw();
    }
};
