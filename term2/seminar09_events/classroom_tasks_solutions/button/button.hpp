#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

// Класс кнопки
class Button
{
private:
    // Статические поля класса, это поля общие для всех экземпляров класса
    inline static const sf::Color defaultColor {220, 220, 220};
    inline static const sf::Color hoverColor   {180, 200, 180};
    inline static const sf::Color pressedColor {140, 160, 140};
    inline static sf::RectangleShape shape {};

    // Тонкий момент: мы храним ссылку на шрифт sf::Font
    // Шрифт может занимать много памяти
    // Чтобы не копировать его для каждой кнопки, мы храним ссылку
    sf::Font& font;

    // Также храним ссылкы на окно SFML, на которое будем отрисовывать кнопку
    // Эту ссылку можно было не хранить, а просто передавать во все функции,
    // где окно понадобится, но тогда код был бы более громоздким
    sf::RenderWindow& sfmlWindow;

    // Текст, границы прямоугольника и текущий цвет кнопки
    sf::Text text;
    sf::FloatRect rect;
    sf::Color currentColor;
    
    // Когда кнопка находится в нажатом состоянии, 
    // то isPressed = true (Пользователь зажал кнопку и держит)
    bool isPressed;

public:

    // Конструктор: ссылки нужно обязательно инициализировать в списке инициализации
    Button(sf::RenderWindow& window, sf::FloatRect rect, sf::Font& font, int fontSize, const sf::String& textData) 
            : font(font), sfmlWindow(window), rect(rect)
    {
        text.setFont(font);
        text.setString(textData);
        text.setCharacterSize(fontSize);
        text.setFillColor(sf::Color::Black);
        sf::FloatRect textRect = text.getLocalBounds();

        text.setPosition(rect.left + (rect.width - textRect.width) / 2, 
                         rect.top  + (rect.height - textRect.height) / 2);

        currentColor = defaultColor;
        isPressed = false;
    }

    // Метод, который рисует кнопку на холсте окна sfmlWindow
    void draw()
    {
        shape.setPosition({rect.left, rect.top});
        shape.setSize({rect.width, rect.height});
        shape.setFillColor(currentColor);
        sfmlWindow.draw(shape);
        sfmlWindow.draw(text);
    }

    // Метод, который срабатывает каждый раз, когда двигается мышь
    void onMouseMove(const sf::Event& event)
    {
        if (isPressed) {
            return;
        }
        sf::Vector2f mouseCoords = sfmlWindow.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
        if (rect.contains(mouseCoords)) {
            currentColor = hoverColor;
        }
        else {
            currentColor = defaultColor;
        }
    }

    // Метод, который срабатывает каждый раз, когда нажимется кнопка мыши
    void onMousePressed(const sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mouseCoords = sfmlWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
            if (rect.contains(mouseCoords)) {
                isPressed = true;
                currentColor = pressedColor;
            }
        }
    }

    // Метод, который срабатывает каждый раз, когда отпускается кнопка мыши
    // Возвращает true, если нажатие на кнопку произошло
    bool onMouseReleased(const sf::Event& event)
    { 
        if (!isPressed) {
            return false;
        }
        isPressed = false;

        sf::Vector2f mouseCoords = sfmlWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
        if (rect.contains(mouseCoords)) {
            currentColor = hoverColor;
            return true;
        }
        else {
            currentColor = defaultColor;
            return false;
        }
    }

    // Нужно вызвать лишь этот метод в цикле обработки событий
    bool handleEvent(const sf::Event& event) {
        if (event.type == sf::Event::MouseMoved) {
            onMouseMove(event);
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            onMousePressed(event);
        }
        else if (event.type == sf::Event::MouseButtonReleased) {
            return onMouseReleased(event);
        }
        return false;
    }
};