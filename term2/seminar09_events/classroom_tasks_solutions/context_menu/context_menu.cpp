#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class ContextMenu
{
private:
    inline static const sf::Color defaultColor {sf::Color(190, 210, 190)};
    inline static const sf::Color hoverColor {sf::Color(150, 170, 150)};
    inline static const sf::Color textColor {sf::Color::Red};
    inline static const int buttonSizeY = 20;
    inline static const int characterSize = 16;

    sf::RectangleShape shape;
    sf::RectangleShape hoverShape;
    sf::Font& font;
    sf::Text text;

    std::vector<std::string> buttons;

    bool isOpened = false;
    bool isUpdated = false;
    int hoverPosition = -1;

public:

    ContextMenu(sf::Font& font) : font(font)
    {   
        text.setFont(font);

        text.setCharacterSize(characterSize);
        text.setFillColor(sf::Color::Black);

        shape.setFillColor(defaultColor);
        hoverShape.setFillColor(hoverColor);

        isOpened = false;
        isUpdated = false;
        hoverPosition = -1;
    }

    void addButton(std::string name)
    {
        buttons.push_back(name);
        isUpdated = false;
    }

    void draw(sf::RenderWindow& window)
    {
        if (!isOpened) {
            return;
        }
        
        if (!isUpdated) {
            int maxSizeX = 0;
            for (int i = 0; i < buttons.size(); i++) 
            {
                text.setString(buttons[i]);
                if (text.getLocalBounds().width > maxSizeX)
                    maxSizeX = text.getLocalBounds().width;
            }
            maxSizeX *= 1.2;
            shape.setSize({(float)maxSizeX, (float)(buttonSizeY * buttons.size())});
            hoverShape.setSize({(float)maxSizeX, (float)(buttonSizeY)});
            isUpdated = true;
        }


        window.draw(shape);
        if (hoverPosition >= 0){
            hoverShape.setPosition(shape.getPosition().x, shape.getPosition().y + hoverPosition * buttonSizeY);
            window.draw(hoverShape);
        }
        for (int i = 0; i < buttons.size(); i++) {
            text.setString(buttons[i]);
            text.setPosition(shape.getPosition().x, shape.getPosition().y + i * buttonSizeY);
            window.draw(text);
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
        if (event.mouseButton.button == sf::Mouse::Right) {
            isOpened = true;
            shape.setPosition({(float)event.mouseButton.x, (float)event.mouseButton.y});
        }
        if (event.mouseButton.button == sf::Mouse::Left && isOpened) {
            isOpened = false;
            return hoverPosition;
        }
        return -1;
    }

    void onMouseHover(sf::Event& event, sf::RenderWindow& window)
    {
        if (!isOpened) {
            return;
        }
        if (checkCollision(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
            hoverPosition = (sf::Mouse::getPosition(window).y - shape.getPosition().y) / buttonSizeY;
        }
        else {
            hoverPosition = -1;
        }
    }

};






int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello world!");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("consolas.ttf")) {
        std::cout << "Can't load button font" << std::endl;
    }

    ContextMenu context_menu(font);
    context_menu.addButton("Cut");
    context_menu.addButton("Copy");
    context_menu.addButton("Paste");
    context_menu.addButton("Select All");
    context_menu.addButton("Options");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseMoved) {
                context_menu.onMouseHover(event, window);
            }

            if (event.type == sf::Event::MouseButtonPressed) {

                // Тут получаем 
                int contextMenuPressResult = context_menu.onMousePressed(event);
                if (contextMenuPressResult == 0) {
                    std::cout << "Cut" << std::endl;
                }
                else if (contextMenuPressResult == 1) {
                    std::cout << "Copy" << std::endl;
                }
                else if (contextMenuPressResult == 2) {
                    std::cout << "Paste" << std::endl;
                }
                else if (contextMenuPressResult == 3) {
                    std::cout << "Select All" << std::endl;
                }
                else if (contextMenuPressResult == 4) {
                    std::cout << "Options" << std::endl;
                }
                
            }

        }
        window.clear(sf::Color::Black);

        context_menu.draw(window);
        window.display();
    }

    return 0;
}