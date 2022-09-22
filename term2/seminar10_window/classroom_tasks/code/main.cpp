#include <SFML/Graphics.hpp>
#include <iostream>
#include <tuple>
#include <cstdlib>
#include <chrono>
#include <thread>

class Button{
    public:
        float lefttopcornerx;
        float lefttopcornery;
        float height;
        float width;
        std::string textin;
        int red;
        int green;
        int blue;
    Button(int ltcx, int ltcy, std::string t, int r, int g, int b){
    lefttopcornerx = ltcx;
    lefttopcornery = ltcy;
    height = 60;
    width = 100;
    textin = t;
    red = r;
    green = g;
    blue = b;
    }
        void draw(sf::RenderWindow &window){
        sf::Text text;
        sf::Font font;
        font.loadFromFile("octin.ttf");
        text.setFont(font);
        text.setString(textin);
        text.setCharacterSize(12);
        text.setFillColor(sf::Color::White);
        text.setPosition(lefttopcornerx + 15, lefttopcornery +8);

        sf::RectangleShape Butn;
        Butn.setSize(sf::Vector2f(width, height));
        Butn.setFillColor(sf::Color(red,green,blue,180));
        Butn.setPosition(lefttopcornerx, lefttopcornery);
        window.draw(Butn);
        window.draw(text);
    }
    bool check_mouse(const sf::Vector2i& p){
        sf::Vector2f left_top_point={lefttopcornerx,lefttopcornery};
        float left_x = left_top_point.x;
        float right_x  = left_top_point.x + width ;
        float left_y = left_top_point.y;
        float right_y  = left_top_point.y + height;
        if (p.x > left_x && p.x < right_x && p.y > left_y && p.y < right_y)
            return true;
        return false;
        
        }
};

int main()
{
 sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(30);
        sf::Mouse ms;
    sf::CircleShape circle(20);
    Button Left(200,450, "Left", 255, 0, 0);
    Button Down(1, 450, "Down", 255, 0, 0);
    Button Right(550, 450, "Right", 255, 0, 0);
    Button Up(680, 450, "Up", 255, 0, 0);
    Left.draw(window);
    Down.draw(window);
    Right.draw(window);
    Up.draw(window);
    window.display();
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
            {
                if(Up.check_mouse(sf::Mouse::getPosition(window)))
                   Up.red=155;
                else
                   Up.red=255;
                if(Down.check_mouse(sf::Mouse::getPosition(window)))
                   Down.red=155;
                else
                   Down.red=255;
                if(Right.check_mouse(sf::Mouse::getPosition(window)))
                   Right.red=155;
                else
                   Right.red=255;
                if(Left.check_mouse(sf::Mouse::getPosition(window)))
                   Left.red=155;
                else
                   Left.red=255;
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Up.check_mouse(sf::Mouse::getPosition(window)))
                {
                    circle.move({0,-20});
                    window.clear(sf::Color::Black);
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Down.check_mouse(sf::Mouse::getPosition(window)))
                {
                    circle.move({0,20});
                    window.clear(sf::Color::Black);

                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Right.check_mouse(sf::Mouse::getPosition(window)))
                {
                    circle.move({20,0});
                    window.clear(sf::Color::Black);

                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Left.check_mouse(sf::Mouse::getPosition(window)))
                {
                    circle.move({-20,0});
                    window.clear(sf::Color::Black);

                }

            }
        window.clear(sf::Color::Black);
        Left.draw(window);
        Down.draw(window);
        Right.draw(window);
        Up.draw(window);
        window.draw(circle);
        window.display();
    }
    return 0;
}
