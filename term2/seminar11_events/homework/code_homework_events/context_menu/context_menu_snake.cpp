#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "context_menu_snake.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Context Menu Test");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("consolas.ttf")) {
        std::cout << "Can't load button font" << std::endl;
    }

    std::vector<sf::String> context_menu_strings {"Add Button", "Cut", "Copy", "Paste", "Select All"};
    Context_menu context_menu(window, font);
    for (const auto& el : context_menu_strings) {
        context_menu.add_button(el);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            int result = context_menu.handle_event(event);
            if (result >= 0) {
                std::cout << (std::string)context_menu_strings[result] << std::endl;
            }
            if (result == 0) {
                context_menu_strings.push_back("New Button");
                context_menu.add_button("New Button");
            }
        }
        window.clear(sf::Color::Black);

        context_menu.draw();
        window.display();
    }
    return 0;
}