#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Movable
{
private:
    sf::RenderWindow& sfmlWindow;

    sf::Color color {sf::Color(200, 200, 200)};
    sf::FloatRect rect;

    bool isBeingDragged;
    sf::Vector2f startDragMousePosition;
    sf::Vector2f rectOffset;

public:

    Movable(sf::RenderWindow& sfmlWindow, sf::FloatRect rect) :
            sfmlWindow(sfmlWindow), rect(rect)
    {
        isBeingDragged = false;
    }

    void setColor(sf::Color newColor) 
    {
        color = newColor;
    }

    sf::Color getColor() 
    {
        return color;
    }

    void onMousePressed(const sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mouse = sfmlWindow.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
            if (rect.contains(mouse)) {
                isBeingDragged = true;
                startDragMousePosition = mouse;
                rectOffset = mouse - sf::Vector2f{rect.left, rect.top};
            }
        }
    }

    void onMouseReleased(const sf::Event& event)
    {
        if (!isBeingDragged) {
            return;
        }
        isBeingDragged = false;
    }

    void onMouseMoved(const sf::Event& event)
    {
        if (!isBeingDragged) {
            return;
        }
        sf::Vector2f mousePosition = sfmlWindow.mapPixelToCoords(sf::Mouse::getPosition(sfmlWindow));// {event.mouseMove.x, event.mouseMove.y};

        sf::Vector2f newPosition = mousePosition - rectOffset;
        rect.left = newPosition.x;
        rect.top = newPosition.y;
    }


    void handleEvent(const sf::Event& event) 
    {
        if (event.type == sf::Event::MouseMoved) {
            onMouseMoved(event);
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            onMousePressed(event);
        }
        else if (event.type == sf::Event::MouseButtonReleased) {
            return onMouseReleased(event);
        }
    }

    void draw() 
    {
    	static sf::RectangleShape shape {};
        shape.setPosition({rect.left, rect.top});
        shape.setSize({rect.width, rect.height});
        shape.setFillColor(color);
        sfmlWindow.draw(shape);
    }
};
