#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;


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




class Checkbox
{
private:
    static const int boundary_size;
    static const int outer_size;
    static const int inner_size;

    static const sf::Color outer_color;
    static const sf::Color inner_color;
    static const sf::Color text_color;


    sf::RectangleShape outer_shape;
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







class ContextMenu
{
private:
    static const sf::Color default_color;
    static const sf::Color hover_color;
    static const sf::Color text_color;
    static const int button_size_y;
    static const int character_size;

    sf::RectangleShape shape;
    sf::RectangleShape hover_shape;
    sf::Font& font;
    sf::Text text;

    std::vector<std::string> buttons;

    bool is_opened = false;
    bool is_updated = false;
    int hover_position = -1;

public:

    ContextMenu(sf::Font& font) : font(font)
    {   
        text.setFont(font);

        text.setCharacterSize(character_size);
        text.setFillColor(sf::Color::Black);

        shape.setFillColor(default_color);
        hover_shape.setFillColor(hover_color);

        is_opened = false;
        is_updated = false;
        hover_position = -1;
    }

    void addButton(std::string name)
    {
        buttons.push_back(name);
        is_updated = false;
    }

    void draw(sf::RenderWindow& window)
    {
        if (is_opened)
        {
            if (!is_updated)
            {
                int max_button_size_x = 0;
                for (int i = 0; i < buttons.size(); i++)
                {
                    text.setString(buttons[i]);
                    if (text.getLocalBounds().width > max_button_size_x)
                        max_button_size_x = text.getLocalBounds().width;
                }
                max_button_size_x *= 1.2;
                shape.setSize({(float)max_button_size_x, (float)(button_size_y * buttons.size())});
                hover_shape.setSize({(float)max_button_size_x, (float)(button_size_y)});
                is_updated = true;

            }


            window.draw(shape);
            if (hover_position >= 0)
            {
                hover_shape.setPosition(shape.getPosition().x, shape.getPosition().y + hover_position * button_size_y);
                window.draw(hover_shape);
            }
            for (int i = 0; i < buttons.size(); i++)
            {
                text.setString(buttons[i]);
                text.setPosition(shape.getPosition().x, shape.getPosition().y + i * button_size_y);
                window.draw(text);
            }
        }
    }

    bool checkCollision(int x, int y)
    {
        return (x > shape.getPosition().x && 
                x < shape.getPosition().x + shape.getSize().x &&
                y > shape.getPosition().y &&
                y < shape.getPosition().y + shape.getSize().y);
    }

    int onMousePressed(sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Right)
        {
            is_opened = true;
            shape.setPosition({(float)event.mouseButton.x, (float)event.mouseButton.y});
        }
        if (event.mouseButton.button == sf::Mouse::Left && is_opened)
        {
            is_opened = false;
            return hover_position;
        }
        return -1;
    }

    void onMouseHover(sf::Event& event, sf::RenderWindow& window)
    {
        if (!is_opened)
            return;
        if (checkCollision(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
        {
            hover_position = (sf::Mouse::getPosition(window).y - shape.getPosition().y) / button_size_y;
        }
        else
        {
            hover_position = -1;
        }
    }

};


const sf::Color ContextMenu::default_color = sf::Color(190, 210, 190);
const sf::Color ContextMenu::hover_color = sf::Color(150, 170, 150);
const sf::Color ContextMenu::text_color = sf::Color::Red;
const int ContextMenu::character_size = 16;
const int ContextMenu::button_size_y = 20;




int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello world!");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("consolas.ttf"))
    {
        cout << "Can't load button font" << endl;
    }

    Button button(200, 200, 160, 60, font, "Hello world!");

    std::vector<Checkbox> checkboxes = { 
        {400, 100, font, "Moscow"},
        {400, 150, font, "New York"},
        {400, 200, font, "Paris"},
        {400, 250, font, "Lagos"},
        {400, 300, font, "Tokyo"},
        {400, 350, font, "Lima"}
    };


    ContextMenu context_menu(font);
    context_menu.addButton("Cut");
    context_menu.addButton("Copy");
    context_menu.addButton("Paste");
    context_menu.addButton("Select All");
    context_menu.addButton("Options");

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
                context_menu.onMouseHover(event, window);
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                button.onMousePressed(event);;
                for (int i = 0; i < checkboxes.size(); i++)
                {
                    checkboxes[i].onMousePressed(event, window);
                }

                // Тут получаем 
                int context_menu_press_result = context_menu.onMousePressed(event);
                if (context_menu_press_result == 0)
                    std::cout << "Cut" << std::endl;
                if (context_menu_press_result == 1)
                    std::cout << "Copy" << std::endl;
                if (context_menu_press_result == 2)
                    std::cout << "Paste" << std::endl;
                if (context_menu_press_result == 3)
                    std::cout << "Select All" << std::endl;
                if (context_menu_press_result == 4)
                    std::cout << "Options" << std::endl;
                
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                button.onMouseReleased(event);
            }

        }
        window.clear(sf::Color::Black);
        button.draw(window);
        

        checkboxes[0].draw(window);
        for (int i = 0; i < checkboxes.size(); i++)
            checkboxes[i].draw(window);

        context_menu.draw(window);
        window.display();
    }

    return 0;
}