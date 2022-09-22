#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Movable
{
private:
    sf::RenderWindow* mpSfmlWindow = nullptr;

    sf::Color mColor {sf::Color(100, 100, 200)};
    sf::FloatRect rect {};

    bool mIsBeingDragged = false;
    sf::Vector2f mStartDragPosition {};
    sf::Vector2f mRectOffset {};

public:

    Movable(sf::RenderWindow* pSfmlWindow, sf::FloatRect rect) :
            mpSfmlWindow(pSfmlWindow), rect(rect)
    {
        mIsBeingDragged = false;
    }

    void setColor(sf::Color newColor) 
    {
        mColor = newColor;
    }

    sf::Color getColor() 
    {
        return mColor;
    }

    void onMousePressed(const sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left) 
        {
            sf::Vector2f mouse = mpSfmlWindow->mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
            if (rect.contains(mouse)) 
            {
                mIsBeingDragged = true;
                mStartDragPosition = mouse;
                mRectOffset = mouse - sf::Vector2f{rect.left, rect.top};
            }
        }
    }

    void onMouseReleased(const sf::Event& event)
    {
        if (!mIsBeingDragged)
            return;

        mIsBeingDragged = false;
    }

    void onMouseMoved(const sf::Event& event)
    {
        if (!mIsBeingDragged) 
            return;

        sf::Vector2f mousePosition = mpSfmlWindow->mapPixelToCoords(sf::Mouse::getPosition(*mpSfmlWindow));// {event.mouseMove.x, event.mouseMove.y};
        sf::Vector2f newPosition = mousePosition - mRectOffset;
        rect.left = newPosition.x;
        rect.top = newPosition.y;
    }


    void handleEvent(const sf::Event& event) 
    {
        if (event.type == sf::Event::MouseMoved)
            onMouseMoved(event);

        else if (event.type == sf::Event::MouseButtonPressed)
            onMousePressed(event);
            
        else if (event.type == sf::Event::MouseButtonReleased)
            return onMouseReleased(event);
    }

    void draw() 
    {
    	static sf::RectangleShape shape {};
        shape.setPosition({rect.left, rect.top});
        shape.setSize({rect.width, rect.height});
        shape.setFillColor(mColor);
        mpSfmlWindow->draw(shape);
    }
};
