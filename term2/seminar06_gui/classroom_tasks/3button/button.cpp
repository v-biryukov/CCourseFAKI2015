#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;



// Класс кнопки
class Button
{
private:
    // Статические поля класса, это поля общие для всех экземпляров класса
    // Они могут быть как константными так и не константными
    static const sf::Color default_color;
    static const sf::Color hover_color;
    static const sf::Color pressed_color;

    // Тонкий момент: мы храним ссылку на шрифт sf::Font
    // Шрифт может занимать много памяти
    // Чтобы не копировать его для каждой кнопки, мы храним ссылку
    sf::Font& font;

    sf::Text text;
    sf::RectangleShape shape;
    
    // Когда кнопка находится в нажатом состоянии, то is_pressed = true
    // (Пользователь зажал кнопку и держит)
    bool is_pressed = false;

public:

    // Конструктор: ссылку нужно обязательно инициализировать в списке инициализации, поэтому font(font)
    Button(int x, int y, int width, int height, sf::Font& font, std::string text_data) : font(font)
    {
        text.setFont(font);
        text.setString(text_data);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
        sf::FloatRect text_size = text.getLocalBounds();
        text.setPosition(x + (width - text_size.width)/2, y + height/2 - text_size.height);

        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(default_color);

        is_pressed = false;
    }

    // Метод, который рисует кнопку на холсте окна window
    void draw(sf::RenderWindow& window)
    {
        window.draw(shape);
        window.draw(text);
    }

    // Метод, который проверяет находится ли точка (x, y) внутри прямоугольника shape
    bool checkCollision(int x, int y)
    {
        return (x > shape.getPosition().x && 
                x < shape.getPosition().x + shape.getSize().x &&
                y > shape.getPosition().y &&
                y < shape.getPosition().y + shape.getSize().y);
    }

    // Метод, который срабатывает каждый раз, когда двигается мышь
    void onMouseHover(sf::Event& event)
    {
        if (is_pressed)
            return;
        if (checkCollision(event.mouseMove.x, event.mouseMove.y))
        {
            shape.setFillColor(hover_color);
        }
        else
        {
            shape.setFillColor(default_color);
        }
    }

    // Метод, который срабатывает каждый раз, когда нажимется кнопка мыши
    void onMousePressed(sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (checkCollision(event.mouseButton.x, event.mouseButton.y))
            {
                is_pressed = true;
                shape.setFillColor(pressed_color);
            }
        }
    }

    // Метод, который срабатывает каждый раз, когда отпускается кнопка мыши
    // Возвращает true, если нажатие на кнопку произошло
    bool onMouseReleased(sf::Event& event)
    {
        bool is_activated = false;
        if (is_pressed)
        {
            if (checkCollision(event.mouseButton.x, event.mouseButton.y))
            {
                shape.setFillColor(hover_color);
                is_activated = true;
            }
            else
            {
                shape.setFillColor(default_color);
                is_activated = false;
            }
            is_pressed = false;
        }
        return is_activated;
    }
};

// Зададим константы класса:
const sf::Color Button::default_color = sf::Color(40, 110, 100);
const sf::Color Button::hover_color = sf::Color(60, 150, 120);
const sf::Color Button::pressed_color = sf::Color(100, 220, 220);




int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Button Class!");
    window.setFramerateLimit(10);

    // Создаём шрифт для кнопки
    sf::Font font;
    if (!font.loadFromFile("consolas.ttf"))
    {
        cout << "Can't load button font" << endl;
    }

    // Создаём кнопку
    Button button(200, 200, 160, 60, font, "Hello world!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseMoved)
            {
                button.onMouseHover(event);

            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                button.onMousePressed(event);
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                bool is_button_pressed = button.onMouseReleased(event);
                if (is_button_pressed)
                    std::cout << "Button pressed!" << std::endl;
            }

        }

        window.clear(sf::Color::Black);
        button.draw(window);
        window.display();
    }

    return 0;
}