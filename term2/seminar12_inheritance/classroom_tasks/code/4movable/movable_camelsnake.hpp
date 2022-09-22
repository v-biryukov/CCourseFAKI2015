#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Movable
{
private:
    sf::RenderWindow* p_sfml_window;

    sf::Color color {sf::Color(100, 100, 200)};
    sf::FloatRect rect;

    bool is_being_dragged;
    sf::Vector2f start_drag_mouse_position;
    sf::Vector2f rect_offset;

public:

    Movable(sf::RenderWindow& p_sfml_window, sf::FloatRect rect) :
            p_sfml_window(p_sfml_window), rect(rect)
    {
        is_being_dragged = false;
    }

    void setColor(sf::Color new_color) 
    {
        color = new_color;
    }

    sf::Color getColor() 
    {
        return color;
    }

    void onMousePressed(const sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mouse = p_sfml_window->mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
            if (rect.contains(mouse)) {
                is_being_dragged = true;
                start_drag_mouse_position = mouse;
                rect_offset = mouse - sf::Vector2f{rect.left, rect.top};
            }
        }
    }

    void onMouseReleased(const sf::Event& event)
    {
        if (!is_being_dragged) {
            return;
        }
        is_being_dragged = false;
    }

    void onMouseMoved(const sf::Event& event)
    {
        if (!is_being_dragged) {
            return;
        }
        sf::Vector2f mouse_position = p_sfml_window->mapPixelToCoords(sf::Mouse::getPosition(p_sfml_window));// {event.mouseMove.x, event.mouseMove.y};

        sf::Vector2f new_position = mouse_position - rect_offset;
        rect.left = new_position.x;
        rect.top = new_position.y;
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
        p_sfml_window->draw(shape);
    }
};
