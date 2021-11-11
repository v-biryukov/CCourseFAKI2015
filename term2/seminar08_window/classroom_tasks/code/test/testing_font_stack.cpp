#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

using std::cout;
using std::endl;

// Программа, которая рисует движущийся круг

void test(sf::Font font) {
    cout << font.getLineSpacing(12) << endl;
}

void printFamily(sf::Font font) {
    cout << font.getInfo().family << endl;
    test(font);
    font.loadFromFile("consola.ttf");
    cout << font.getInfo().family << endl;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Moving Circle");

    sf::Font font;
    if (!font.loadFromFile("consola.ttf")) {
        std::cerr << "Error! Can't load font consola.ttf" << endl;
    }

    printFamily(font);

    sf::Text text;
    text.setFont(font);
    text.setString("Testing Font");
    text.setPosition({200, 200});

    while (true) {
        sf::Event event;
        if (window.pollEvent(event)) 
        {
        }

        window.clear(sf::Color::Black);
        window.draw(text);

        window.display();
    }
}