#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


/*
    Класс ContextMenu - контекстное меню
    При нажатии правой кнопки мыши на экране появляется контекстное меню

    Публичные методы:
        ContextMenu(sf::RenderWindow&, const sf::Font&)
            Конструктор принимает окно для отрисовки и шрифт

        void addButton(const sf::String& name)
            Добавить новый элемент в контекстное меню по имени name

        void draw()
            Нарисовать контекстное меню в окне, которое было передано в конструктор

        int handleEvent(const sf::Event& event)
            Обрабатывает событие event и возвращает целое число
            Если это событие MousePressed и был выбран один из вариантов
            контекстного меню, то вернёт номер этого варианта
            Нумерация начинается с нуля
            В ином случае вернёт -1

*/


class ContextMenu
{
private:
    inline static const sf::Color kDefaultColor {sf::Color(190, 210, 190)};
    inline static const sf::Color kHoverColor {sf::Color(150, 170, 150)};
    inline static const sf::Color kTextColor {sf::Color::Black};
    inline static const int kButtonHeight = 20;
    inline static const int kCharacterSize = 16;
    inline static const float kMenuWidthMultiplier = 1.2;

    sf::RenderWindow& m_renderWindow;
    sf::RectangleShape m_shape;
    sf::RectangleShape m_hoverShape;
    sf::Text m_text;

    std::vector<sf::String> m_buttons;

    bool m_isOpened = false;
    bool m_isUpdated = false;
    int m_hoverPosition = -1;

    int onMousePressed(const sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Right) {
            m_isOpened = true;
            sf::Vector2f mousePosition = m_renderWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
            m_shape.setPosition(mousePosition);
        }
        if (event.mouseButton.button == sf::Mouse::Left && m_isOpened) {
            m_isOpened = false;
            return m_hoverPosition;
        }
        return -1;
    }

    void onMouseMove(const sf::Event& event)
    {
        if (!m_isOpened) {
            return;
        }
        sf::Vector2f mousePosition = m_renderWindow.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
        if (m_shape.getGlobalBounds().contains(mousePosition)) {
            m_hoverPosition = (mousePosition.y - m_shape.getPosition().y) / kButtonHeight;
        }
        else {
            m_hoverPosition = -1;
        }
    }

public:

    ContextMenu(sf::RenderWindow& window, const sf::Font& font) : m_renderWindow(window)
    {   
        m_text.setFont(font);
        m_text.setCharacterSize(kCharacterSize);
        m_text.setFillColor(kTextColor);
        m_shape.setFillColor(kDefaultColor);
        m_hoverShape.setFillColor(kHoverColor);

        m_isOpened = false;
        m_isUpdated = false;
        m_hoverPosition = -1;
    }

    void addButton(const sf::String& name)
    {
        m_buttons.push_back(name);
        m_isUpdated = false;
    }

    void draw()
    {
        if (!m_isOpened) {
            return;
        }
        
        // Если добавили новый вариант, то её текст может быть длиннее
        // чем у других. Нужно расширить прямоугольники.
        if (!m_isUpdated) {
            int maxSizeX = 0;
            for (int i = 0; i < m_buttons.size(); i++) {
                m_text.setString(m_buttons[i]);
                if (m_text.getLocalBounds().width > maxSizeX) {
                    maxSizeX = m_text.getLocalBounds().width;
                }
            }
            maxSizeX *= kMenuWidthMultiplier;
            m_shape.setSize({(float)maxSizeX, (float)(kButtonHeight * m_buttons.size())});
            m_hoverShape.setSize({(float)maxSizeX, (float)(kButtonHeight)});
            m_isUpdated = true;
        }


        m_renderWindow.draw(m_shape);
        if (m_hoverPosition >= 0){
            m_hoverShape.setPosition(m_shape.getPosition().x, m_shape.getPosition().y + m_hoverPosition * kButtonHeight);
            m_renderWindow.draw(m_hoverShape);
        }
        for (int i = 0; i < m_buttons.size(); i++) {
            m_text.setString(m_buttons[i]);
            m_text.setPosition(m_shape.getPosition().x, m_shape.getPosition().y + i * kButtonHeight);
            m_renderWindow.draw(m_text);
        }
    }

    int handleEvent(const sf::Event& event) {
        if (event.type == sf::Event::MouseMoved) {
            onMouseMove(event);
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            return onMousePressed(event);
        }
        return -1;
    }

};