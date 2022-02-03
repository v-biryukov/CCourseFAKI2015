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

    void set_color(sf::Color new_color) 
    {
        color = new_color;
    }

    sf::Color get_color() 
    {
        return color;
    }

    void on_mouse_pressed(const sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mouse = p_sfml_window->mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
            if (this->rect.contains(mouse)) {
                this->is_being_dragged = true;
                this->start_drag_mouse_position = mouse;
                this->rect_offset = mouse - sf::Vector2f{rect.left, rect.top};
            }
        }
    }

    void on_mouse_released(const sf::Event& event)
    {
        if (!is_being_dragged) {
            return;
        }
        is_being_dragged = false;
    }

    void on_mouse_moved(const sf::Event& event)
    {
        if (!is_being_dragged) {
            return;
        }
        sf::Vector2f mouse_position = p_sfml_window->mapPixelToCoords(sf::Mouse::getPosition(p_sfml_window));// {event.mouseMove.x, event.mouseMove.y};

        sf::Vector2f new_position = mouse_position - rect_offset;
        rect.left = new_position.x;
        rect.top = new_position.y;
    }


    void handle_event(const sf::Event& event) 
    {
        if (event.type == sf::Event::MouseMoved) {
            on_mouse_moved(event);
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            on_mouse_pressed(event);
        }
        else if (event.type == sf::Event::MouseButtonReleased) {
            return on_mouse_released(event);
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
