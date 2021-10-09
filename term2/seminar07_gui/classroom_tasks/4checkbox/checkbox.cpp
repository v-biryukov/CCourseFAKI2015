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

    void draw(sf::RenderWindow& window)
    {
        window.draw(shape);
        window.draw(text);
    }

    bool checkCollision(int x, int y)
    {
        return (x > shape.getPosition().x && 
                x < shape.getPosition().x + shape.getSize().x &&
                y > shape.getPosition().y &&
                y < shape.getPosition().y + shape.getSize().y);
    }

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



// Класс флажка
class Checkbox
{
private:
    // Статические константы, общие для всех флажков
    static const int boundary_size;
    static const int outer_size;
    static const int inner_size;

    static const sf::Color outer_color;
    static const sf::Color inner_color;
    static const sf::Color text_color;


    // Внешний квадратик
    sf::RectangleShape outer_shape;
    // Внутрений квадратик
    sf::RectangleShape inner_shape;
    sf::Font& font;
    sf::Text text;

    bool is_activated = false;

public:
    Checkbox(int x, int y, sf::Font& font, std::string text_data) : font(font)
    {
        text.setFont(font);
        text.setString(text_data);
        text.setCharacterSize(24);
        text.setFillColor(text_color);
        sf::FloatRect text_size = text.getLocalBounds();
        text.setPosition(x + boundary_size, y + boundary_size/2 - text_size.height);

        outer_shape.setPosition(x + boundary_size/2 - outer_size/2, y + boundary_size/2 - outer_size/2);
        outer_shape.setSize(sf::Vector2f(outer_size, outer_size));
        outer_shape.setFillColor(outer_color);

        inner_shape.setPosition(x + boundary_size/2 - inner_size/2, y + boundary_size/2 - inner_size/2);
        inner_shape.setSize(sf::Vector2f(inner_size, inner_size));
        inner_shape.setFillColor(inner_color);

        is_activated = false;
        text.setFont(font);
    }
    bool isActivated()
    {
        return is_activated;
    }

    std::string getTitle()
    {
        return text.getString();
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(text);
        window.draw(outer_shape);
        if (is_activated)
            window.draw(inner_shape);
    }

    bool checkCollision(int x, int y)
    {
        return (x > outer_shape.getPosition().x && 
                x < outer_shape.getPosition().x + outer_shape.getSize().x &&
                y > outer_shape.getPosition().y &&
                y < outer_shape.getPosition().y + outer_shape.getSize().y);
    }

    void onMousePressed(sf::Event& event, sf::RenderWindow& window)
    {
        sf::Vector2f world_pos = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            //if (checkCollision(event.mouseButton.x, event.mouseButton.y))
            if (checkCollision(world_pos.x, world_pos.y))
            {
                is_activated = !is_activated;
            }
        }
    }
};





const int Checkbox::boundary_size = 24;
const int Checkbox::outer_size = 16;
const int Checkbox::inner_size = 10;

const sf::Color Checkbox::text_color = sf::Color::White;
const sf::Color Checkbox::outer_color = sf::Color::White;
const sf::Color Checkbox::inner_color = sf::Color::Black;




int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Button Class!");
    window.setFramerateLimit(10);

    // Это для надписи вверху слева:
    sf::Font consolas_font;
    if (!consolas_font.loadFromFile("consolas.ttf"))
    {
        cout << "Can't load button font consolas.txt" << endl;
    }
    sf::Text info;
    info.setFont(consolas_font);
    info.setString("Checkboxes activated :");
    info.setCharacterSize(22);


    Button button(200, 200, 160, 60, consolas_font, "Hello world!");

    std::vector<Checkbox> checkboxes = { 
        {400, 100, consolas_font, "Moscow"},
        {400, 150, consolas_font, "New York"},
        {400, 200, consolas_font, "Paris"},
        {400, 250, consolas_font, "Lagos"},
        {400, 300, consolas_font, "Tokyo"},
        {400, 350, consolas_font, "Lima"}
    };

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

                // Проверяем на нажатие все флажки
                for (int i = 0; i < checkboxes.size(); i++)
                {
                    checkboxes[i].onMousePressed(event, window);
                }
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                // Смотрим, что возвращает onMouseReleased (нажалась ли кнопка)
                bool is_button_pressed = button.onMouseReleased(event);
                if (is_button_pressed)
                    std::cout << "Button pressed!" << std::endl;
            }

        }

        window.clear(sf::Color::Black);
        button.draw(window);
        for (int i = 0; i < checkboxes.size(); i++)
            checkboxes[i].draw(window);

        window.draw(info);
        window.display();
    }

    return 0;
}