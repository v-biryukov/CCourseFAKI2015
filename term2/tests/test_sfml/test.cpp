#include <iostream>
#include <cmath>
#include <list>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



class Button
{

private:

    sf::CircleShape shape;
    sf::Color color = sf::Color(255,255,255);

    float radius = 200;



public:

    Button(float x, float y, float radius)
    {
        shape.setPosition(x, y);
        shape.setRadius(radius);
        shape.setOrigin(radius, radius);
        shape.setFillColor(sf::Color(255, 255, 255));

    }



    void draw(sf::RenderWindow& window)
    {
        window.draw(shape);
    }

    void changeColor(std::string r, std::string g, std::string b)
    {
        int R = std::stoi(r);
        int G = std::stoi(g);
        int B = std::stoi(b);
        shape.setFillColor(sf::Color(R, G, B));
    }
    

};


class Line
{
private:
    static const sf::Color color;
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font& font;


    float width = 220;
    float height = 6;



public:




    Line(float x, float y, sf::Font& font, std::string number) : font(font)
    {

        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(color);
        text.setString(number);
        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        sf::FloatRect text_size = text.getLocalBounds();
        text.setPosition(x + width + width * 20 / 100, y - text.getCharacterSize() / 2);
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(shape);
        window.draw(text);
    }



    void ChangeNumber(std::string number)
    {

        text.setString(number);

    }
    bool CheckLine(int x, int y)
    {
        return (x > shape.getPosition().x) &&
            x < shape.getPosition().x + (shape.getSize().x) &&
            y > shape.getPosition().y &&
            y < shape.getPosition().y + (shape.getSize().y);
    }

    float getWidth()
    {
        float temp = shape.getPosition().x - width * 50 / 100;
        return temp;
    }
    float getHeight()
    {
        float temp = shape.getPosition().y + height / 2;;
        return temp;
    }
};

const sf::Color Line::color = sf::Color(0, 255, 255);


class Slider_1
{
private:
    static const sf::Color color;
    static const sf::Color color_pressed;
    sf::RectangleShape shape_slider;
    bool is_pressed = false;


    float width = 20;
    float height = 20;


    int max_size = 500;
    int min_size = 300;

    float constY = 0;
    float dx = 0;
    float dy = 0;



public:
    Slider_1(float x, float y)
    {
        shape_slider.setPosition(x, y);
        shape_slider.setSize(sf::Vector2f(width, height));
        shape_slider.setOrigin({ width / 2, height / 2 });
        shape_slider.setFillColor(color);
        constY = y;

    }
    bool CheckCollision(int x, int y)
    {
        return ((x > shape_slider.getPosition().x - (shape_slider.getSize().x) / 2) &&
            x < shape_slider.getPosition().x + (shape_slider.getSize().x) / 2 &&
            (y > shape_slider.getPosition().y - (shape_slider.getSize().y) / 2) &&
            y < shape_slider.getPosition().y + (shape_slider.getSize().y) / 2);
    }

    void onMousePressed(sf::Event& event, float x, float y)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {

            dx = x - shape_slider.getPosition().x;
            dy = y - constY;
            shape_slider.setOrigin({ width / 2 + dx,height / 2 + dy });
            shape_slider.setPosition({ x, y });
            shape_slider.setFillColor(color_pressed);
            is_pressed = true;




        }
    }
    void onMousePressedLine(sf::Event& event, float x, float y)
    {
        dx = 0;
        dy = 0;
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (x < min_size)
            {
                shape_slider.setPosition(min_size, constY);

            }
            else if (x > max_size)
            {
                shape_slider.setPosition(max_size, constY);

            }
            else
            {
                shape_slider.setPosition({ x, constY });
            }
            is_pressed = true;




        }
    }


    void onMouseRealeased(sf::Event& event, float x, float y)
    {
        if (is_pressed)
        {
            if (x < min_size)
            {
                shape_slider.setPosition(min_size, constY);
                shape_slider.setOrigin({ width / 2, height / 2 });

            }
            else if (x > max_size)
            {
                shape_slider.setPosition(max_size, constY);
                shape_slider.setOrigin({ width / 2, height / 2 });

            }
            else 
            {
                shape_slider.setPosition({ x - dx, constY });
                shape_slider.setOrigin({ width / 2, height / 2 });
            }

            shape_slider.setFillColor(color);
            is_pressed = false;
        }


    }

    void onMouseMoved(sf::Event& event, float x, float y)
    {

        if (is_pressed)
        {


            if ((x - dx) < min_size)
            {
                shape_slider.setPosition(min_size + dx, constY + dy);

            }
            else if ((x - dx) > max_size)
            {

                shape_slider.setPosition(max_size + dx, constY + dy);

            }
            else
            {
                shape_slider.setPosition({ x, constY + dy });

            }


        }




    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(shape_slider);

    }
    std::string ChangeNumber()
    {
        int temp = (shape_slider.getPosition().x - dx - min_size) / 200*255;
        std::string number = std::to_string(temp);
        return number;
    }
    bool CheckPressed(sf::Event& event)
    {
        return is_pressed;
    }
};

const sf::Color Slider_1::color = sf::Color(0, 191, 255);
const sf::Color Slider_1::color_pressed = sf::Color(100, 149, 237);

class Slider_2
{
private:
    static const sf::Color color;
    static const sf::Color color_pressed;
    sf::RectangleShape shape_slider;
    bool is_pressed = false;


    float width = 20;
    float height = 20;


    int max_size = 500;
    int min_size = 300;

    float constY = 0;
    float dx = 0;
    float dy = 0;



public:
    Slider_2(float x, float y)
    {
        shape_slider.setPosition(x, y);
        shape_slider.setSize(sf::Vector2f(width, height));
        shape_slider.setOrigin({ width / 2, height / 2 });
        shape_slider.setFillColor(color);
        constY = y;

    }
    bool CheckCollision(int x, int y)
    {
        return ((x > shape_slider.getPosition().x - (shape_slider.getSize().x) / 2) &&
            x < shape_slider.getPosition().x + (shape_slider.getSize().x) / 2 &&
            (y > shape_slider.getPosition().y - (shape_slider.getSize().y) / 2) &&
            y < shape_slider.getPosition().y + (shape_slider.getSize().y) / 2);
    }

    void onMousePressed(sf::Event& event, float x, float y)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {

            dx = x - shape_slider.getPosition().x;
            dy = y - constY;
            shape_slider.setOrigin({ width / 2 + dx,height / 2 + dy });
            shape_slider.setPosition({ x, y });
            shape_slider.setFillColor(color_pressed);
            is_pressed = true;




        }
    }
    void onMousePressedLine(sf::Event& event, float x, float y)
    {
        dx = 0;
        dy = 0;
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (x < min_size)
            {
                shape_slider.setPosition(min_size, constY);

            }
            else if (x > max_size)
            {
                shape_slider.setPosition(max_size, constY);

            }
            else
            {
                shape_slider.setPosition({ x, constY });
            }
            is_pressed = true;




        }
    }


    void onMouseRealeased(sf::Event& event, float x, float y)
    {
        if (is_pressed)
        {
            if (x < min_size)
            {
                shape_slider.setPosition(min_size, constY);
                shape_slider.setOrigin({ width / 2, height / 2 });

            }
            else if (x > max_size)
            {
                shape_slider.setPosition(max_size, constY);
                shape_slider.setOrigin({ width / 2, height / 2 });

            }
            else
            {
                shape_slider.setPosition({ x - dx, constY });
                shape_slider.setOrigin({ width / 2, height / 2 });
            }

            shape_slider.setFillColor(color);
            is_pressed = false;
        }


    }

    void onMouseMoved(sf::Event& event, float x, float y)
    {

        if (is_pressed)
        {


            if ((x - dx) < min_size)
            {
                shape_slider.setPosition(min_size + dx, constY + dy);

            }
            else if ((x - dx) > max_size)
            {

                shape_slider.setPosition(max_size + dx, constY + dy);

            }
            else
            {
                shape_slider.setPosition({ x, constY + dy });

            }


        }




    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(shape_slider);

    }
    std::string ChangeNumber()
    {
        int temp = (shape_slider.getPosition().x - dx - min_size) / 200*255;
        std::string number = std::to_string(temp);
        return number;
    }
    bool CheckPressed(sf::Event& event)
    {
        return is_pressed;
    }
};

const sf::Color Slider_2::color = sf::Color(0, 191, 255);
const sf::Color Slider_2::color_pressed = sf::Color(100, 149, 237);

class Slider_3
{
private:
    static const sf::Color color;
    static const sf::Color color_pressed;
    sf::RectangleShape shape_slider;
    bool is_pressed = false;


    float width = 20;
    float height = 20;


    int max_size = 500;
    int min_size = 300;

    float constY = 0;
    float dx = 0;
    float dy = 0;



public:
    Slider_3(float x, float y)
    {
        shape_slider.setPosition(x, y);
        shape_slider.setSize(sf::Vector2f(width, height));
        shape_slider.setOrigin({ width / 2, height / 2 });
        shape_slider.setFillColor(color);
        constY = y;

    }
    bool CheckCollision(int x, int y)
    {
        return ((x > shape_slider.getPosition().x - (shape_slider.getSize().x) / 2) &&
            x < shape_slider.getPosition().x + (shape_slider.getSize().x) / 2 &&
            (y > shape_slider.getPosition().y - (shape_slider.getSize().y) / 2) &&
            y < shape_slider.getPosition().y + (shape_slider.getSize().y) / 2);
    }

    void onMousePressed(sf::Event& event, float x, float y)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {

            dx = x - shape_slider.getPosition().x;
            dy = y - constY;
            shape_slider.setOrigin({ width / 2 + dx,height / 2 + dy });
            shape_slider.setPosition({ x, y });
            shape_slider.setFillColor(color_pressed);
            is_pressed = true;




        }
    }
    void onMousePressedLine(sf::Event& event, float x, float y)
    {
        dx = 0;
        dy = 0;
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (x < min_size)
            {
                shape_slider.setPosition(min_size, constY);

            }
            else if (x > max_size)
            {
                shape_slider.setPosition(max_size, constY);

            }
            else
            {
                shape_slider.setPosition({ x, constY });
            }
            is_pressed = true;




        }
    }


    void onMouseRealeased(sf::Event& event, float x, float y)
    {
        if (is_pressed)
        {
            if (x < min_size)
            {
                shape_slider.setPosition(min_size, constY);
                shape_slider.setOrigin({ width / 2, height / 2 });

            }
            else if (x > max_size)
            {
                shape_slider.setPosition(max_size, constY);
                shape_slider.setOrigin({ width / 2, height / 2 });

            }
            else
            {
                shape_slider.setPosition({ x - dx, constY });
                shape_slider.setOrigin({ width / 2, height / 2 });
            }

            shape_slider.setFillColor(color);
            is_pressed = false;
        }


    }

    void onMouseMoved(sf::Event& event, float x, float y)
    {

        if (is_pressed)
        {


            if ((x - dx) < min_size)
            {
                shape_slider.setPosition(min_size + dx, constY + dy);

            }
            else if ((x - dx) > max_size)
            {

                shape_slider.setPosition(max_size + dx, constY + dy);

            }
            else
            {
                shape_slider.setPosition({ x, constY + dy });

            }


        }




    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(shape_slider);

    }
    std::string ChangeNumber()
    {
        int temp = (shape_slider.getPosition().x - dx - min_size) / 200*255;
        std::string number = std::to_string(temp);
        return number;
    }
    bool CheckPressed(sf::Event& event)
    {
        return is_pressed;
    }
};

const sf::Color Slider_3::color = sf::Color(0, 191, 255);
const sf::Color Slider_3::color_pressed = sf::Color(100, 149, 237);




int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 20;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello world!", sf::Style::Close, settings);
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("consolas.ttf"))
    {
        std::cout << "Can't load button font" << std::endl;
    }

    sf::Font consolas_font;
    if (!consolas_font.loadFromFile("consolas.ttf"))
    {
        std::cout << "Can't load button font consolas.txt" << std::endl;
    }
    sf::Text info;
    info.setFont(consolas_font);
    info.setString("Checkboxes activated :");
    info.setCharacterSize(22);
    Slider_1 slider_1(400, 203);
    Slider_2 slider_2(400, 303);
    Slider_3 slider_3(400, 403);
    std::string number_1 = slider_1.ChangeNumber();
    std::string number_2 = slider_2.ChangeNumber();
    std::string number_3 = slider_3.ChangeNumber();


    Line line_1(290, 200, consolas_font, number_1);
    Line line_2(290, 300, consolas_font, number_2);
    Line line_3(290, 400, consolas_font, number_3);

    Button button(line_2.getWidth(), line_2.getHeight(), 50);




    sf::Vector2f mouse_right_position;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mouse_position = { (float)event.mouseMove.x, (float)event.mouseMove.y };

                slider_1.onMouseMoved(event, (float)event.mouseMove.x, (float)event.mouseMove.y);
                slider_2.onMouseMoved(event, (float)event.mouseMove.x, (float)event.mouseMove.y);
                slider_3.onMouseMoved(event, (float)event.mouseMove.x, (float)event.mouseMove.y);
                if (slider_1.CheckPressed(event))
                {
                    number_1 = slider_1.ChangeNumber();
                }
                if (slider_2.CheckPressed(event))
                {
                    number_2 = slider_2.ChangeNumber();
                }
                if (slider_3.CheckPressed(event))
                {
                    number_3 = slider_3.ChangeNumber();
                }
                line_1.ChangeNumber(number_1);
                line_2.ChangeNumber(number_2);
                line_3.ChangeNumber(number_3);

                button.changeColor(number_1, number_2, number_3);

            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f mouse_position = { (float)event.mouseButton.x, (float)event.mouseButton.y };

                if (slider_1.CheckCollision((float)event.mouseButton.x, (float)event.mouseButton.y))
                {
                    slider_1.onMousePressed(event, (float)event.mouseButton.x, (float)event.mouseButton.y);
                }
                else if (slider_2.CheckCollision((float)event.mouseButton.x, (float)event.mouseButton.y))
                {
                    slider_2.onMousePressed(event, (float)event.mouseButton.x, (float)event.mouseButton.y);
                }
                else if (slider_3.CheckCollision((float)event.mouseButton.x, (float)event.mouseButton.y))
                {
                    slider_3.onMousePressed(event, (float)event.mouseButton.x, (float)event.mouseButton.y);
                }
                else if ((!slider_1.CheckCollision((float)event.mouseButton.x, (float)event.mouseButton.y)) && line_1.CheckLine((float)event.mouseButton.x, (float)event.mouseButton.y))
                {
                    slider_1.onMousePressedLine(event, (float)event.mouseButton.x, (float)event.mouseButton.y);
                    number_1 = slider_1.ChangeNumber();
                }
                else if ((!slider_2.CheckCollision((float)event.mouseButton.x, (float)event.mouseButton.y)) && line_2.CheckLine((float)event.mouseButton.x, (float)event.mouseButton.y))
                {
                    slider_2.onMousePressedLine(event, (float)event.mouseButton.x, (float)event.mouseButton.y);
                    number_2 = slider_2.ChangeNumber();
                }
                else if ((!slider_3.CheckCollision((float)event.mouseButton.x, (float)event.mouseButton.y)) && line_3.CheckLine((float)event.mouseButton.x, (float)event.mouseButton.y))
                {
                    slider_3.onMousePressedLine(event, (float)event.mouseButton.x, (float)event.mouseButton.y);
                    number_3 = slider_3.ChangeNumber();
                }
                
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                sf::Vector2f mouse_position = { (float)event.mouseButton.x, (float)event.mouseButton.y };
                slider_1.onMouseRealeased(event, (float)event.mouseButton.x, (float)event.mouseButton.y);
                slider_2.onMouseRealeased(event, (float)event.mouseButton.x, (float)event.mouseButton.y);
                slider_3.onMouseRealeased(event, (float)event.mouseButton.x, (float)event.mouseButton.y);

                line_1.ChangeNumber(number_1);
                line_2.ChangeNumber(number_2);
                line_3.ChangeNumber(number_3);
            }

        }
        window.clear(sf::Color::Black);



        line_1.draw(window);
        line_2.draw(window);
        line_3.draw(window);


        slider_1.draw(window);
        slider_2.draw(window);
        slider_3.draw(window);

        button.draw(window);

        window.display();
    }

    return 0;
}
