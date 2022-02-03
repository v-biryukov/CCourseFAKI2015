#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


/*
    Класс Context_menu - контекстное меню
    При нажатии правой кнопки мыши на экране появляется контекстное меню

    Публичные методы:
        Context_menu(sf::RenderWindow&, const sf::Font&)
            Конструктор принимает окно для отрисовки и шрифт

        void add_button(const sf::String& name)
            Добавить новый элемент в контекстное меню по имени name

        void draw()
            Нарисовать контекстное меню в окне, которое было передано в конструктор

        int handle_event(const sf::Event& event)
            Обрабатывает событие event и возвращает целое число
            Если это событие MousePressed и был выбран один из вариантов
            контекстного меню, то вернёт номер этого варианта
            Нумерация начинается с нуля
            В ином случае вернёт -1

*/


class Context_menu
{
private:
    inline static const sf::Color default_color {sf::Color(190, 210, 190)};
    inline static const sf::Color hover_color {sf::Color(150, 170, 150)};
    inline static const sf::Color text_color {sf::Color::Black};
    inline static const int button_height = 20;
    inline static const int character_size = 16;
    inline static const float menu_width_multiplier = 1.2;

    sf::RenderWindow& m_render_window;
    sf::RectangleShape m_shape;
    sf::RectangleShape m_hover_shape;
    sf::Text m_text;

    std::vector<sf::String> m_buttons;

    bool m_is_opened = false;
    bool m_is_updated = false;
    int m_hover_position = -1;

    int on_mouse_pressed(const sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Right) {
            m_is_opened = true;
            sf::Vector2f mouse_position = m_render_window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
            m_shape.setPosition(mouse_position);
        }
        if (event.mouseButton.button == sf::Mouse::Left && m_is_opened) {
            m_is_opened = false;
            return m_hover_position;
        }
        return -1;
    }

    void on_mouse_move(const sf::Event& event)
    {
        if (!m_is_opened) {
            return;
        }
        sf::Vector2f mouse_position = m_render_window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
        if (m_shape.getGlobalBounds().contains(mouse_position)) {
            m_hover_position = (mouse_position.y - m_shape.getPosition().y) / button_height;
        }
        else {
            m_hover_position = -1;
        }
    }

public:

    Context_menu(sf::RenderWindow& window, const sf::Font& font) : m_render_window(window)
    {   
        m_text.setFont(font);
        m_text.setCharacterSize(character_size);
        m_text.setFillColor(text_color);
        m_shape.setFillColor(default_color);
        m_hover_shape.setFillColor(hover_color);
        m_is_opened = false;
        m_is_updated = false;
        m_hover_position = -1;
    }

    void add_button(const sf::String& name)
    {
        m_buttons.push_back(name);
        m_is_updated = false;
    }

    void draw()
    {
        if (!m_is_opened) {
            return;
        }
        
        // Если добавили новый вариант, то её текст может быть длиннее
        // чем у других. Нужно расширить прямоугольники.
        if (!m_is_updated) {
            int max_size_x = 0;
            for (int i = 0; i < m_buttons.size(); i++) {
                m_text.setString(m_buttons[i]);
                if (m_text.getLocalBounds().width > max_size_x) {
                    max_size_x = m_text.getLocalBounds().width;
                }
            }
            max_size_x *= menu_width_multiplier;
            m_shape.setSize({(float)max_size_x, (float)(button_height * m_buttons.size())});
            m_hover_shape.setSize({(float)max_size_x, (float)(button_height)});
            m_is_updated = true;
        }


        m_render_window.draw(m_shape);
        if (m_hover_position >= 0){
            m_hover_shape.setPosition(m_shape.getPosition().x, m_shape.getPosition().y + m_hover_position * button_height);
            m_render_window.draw(m_hover_shape);
        }
        for (int i = 0; i < m_buttons.size(); i++) {
            m_text.setString(m_buttons[i]);
            m_text.setPosition(m_shape.getPosition().x, m_shape.getPosition().y + i * button_height);
            m_render_window.draw(m_text);
        }
    }

    int handle_event(const sf::Event& event) {
        if (event.type == sf::Event::MouseMoved) {
            on_mouse_move(event);
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            return on_mouse_pressed(event);
        }
        return -1;
    }

};