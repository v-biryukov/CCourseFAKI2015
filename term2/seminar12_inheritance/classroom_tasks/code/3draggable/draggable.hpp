#pragma once
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

    void setPosition(sf::Vector2f sz)
    {
        mShape.setSize(sz);
    }

    void draw(sf::RenderWindow& rw) const
    {
        rw.draw(mShape);
    }
};
