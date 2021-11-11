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


    // Тонкий момент: мы храним ссылку на шрифт sf::Font
    // Шрифт может занимать много памяти
    // Чтобы не копировать его для каждой кнопки, мы храним ссылку
    sf::Font& font;

    sf::Text text;
    sf::RectangleShape shape;
    
    // Когда кнопка находится в нажатом состоянии, 
    // то isPressed = true (Пользователь зажал кнопку и держит)
    bool isPressed = false;

public:

    // Конструктор: ссылку font нужно обязательно инициализировать в списке инициализации
    Button(sf::IntRect rect, sf::Font& font, int fontSize, const sf::String& textData) : font(font)
    {
        text.setFont(font);
        text.setString(textData);
        text.setCharacterSize(fontSize);
        text.setFillColor(sf::Color::Black);
        sf::FloatRect textRect = text.getLocalBounds();

        text.setPosition(rect.left + (rect.width - textRect.width) / 2, 
                         rect.top  + (rect.height - textRect.height) / 2);

        shape.setPosition(rect.left, rect.top);
        shape.setSize(sf::Vector2f(rect.width, rect.height));
        shape.setFillColor(defaultColor);

        isPressed = false;
    }

    // Метод, который рисует кнопку на холсте окна window
    void draw(sf::RenderWindow& window) const
    {
        window.draw(shape);
        window.draw(text);
    }

    // Метод, который проверяет находится ли точка (x, y) внутри прямоугольника shape
    bool checkCollision(int x, int y) const
    {
        return (x > shape.getPosition().x && 
                x < shape.getPosition().x + shape.getSize().x &&
                y > shape.getPosition().y &&
                y < shape.getPosition().y + shape.getSize().y);
    }

    // Метод, который срабатывает каждый раз, когда двигается мышь
    void onMouseHover(const sf::Event& event)
    {
        if (isPressed) {
            return;
        }
        if (checkCollision(event.mouseMove.x, event.mouseMove.y)) {
            shape.setFillColor(hoverColor);
        }
        else {
            shape.setFillColor(defaultColor);
        }
    }

    // Метод, который срабатывает каждый раз, когда нажимется кнопка мыши
    void onMousePressed(const sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (checkCollision(event.mouseButton.x, event.mouseButton.y)) {
                isPressed = true;
                shape.setFillColor(pressedColor);
            }
        }
    }

    // Метод, который срабатывает каждый раз, когда отпускается кнопка мыши
    // Возвращает true, если нажатие на кнопку произошло
    bool onMouseReleased(const sf::Event& event)
    {
        bool is_activated = false;
        if (isPressed) {
            if (checkCollision(event.mouseButton.x, event.mouseButton.y)) {
                shape.setFillColor(hoverColor);
                is_activated = true;
            }
            else {
                shape.setFillColor(defaultColor);
                is_activated = false;
            }
            isPressed = false;
        }
        return is_activated;
    }


    bool handleEvent(const sf::Event& event) {
        if (event.type == sf::Event::MouseMoved) {
            onMouseHover(event);
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

// Зададим константы класса:

