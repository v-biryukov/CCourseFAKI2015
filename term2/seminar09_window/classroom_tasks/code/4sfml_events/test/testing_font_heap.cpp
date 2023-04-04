#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

using std::cout, std::endl;

// Программа, которая рисует движущийся круг

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Moving Circle");

    sf::Font* pfont1 = new sf::Font;
    if (!pfont1->loadFromFile("consola.ttf")) 
    {
        std::cerr << "Error! Can't load font consola.ttf" << endl;
    }

    sf::Font* pfont2 = pfont1;
    delete pfont2;

    sf::Text text;
    text.setFont(*pfont1);
    text.setString("Testing Font");
    text.setPosition({200, 200});

    while (true) 
    {
        sf::Event event;
        if (window.pollEvent(event)) 
        {
        }

        window.clear(sf::Color::Black);
        window.draw(text);

        window.display();
    }
}