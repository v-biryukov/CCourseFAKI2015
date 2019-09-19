#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>


const int window_width = 400;
const int window_height = 400;

const int start_x = 50;
const int start_y = 50;
const int cell_size = 16;

const int table_size_x = 15;
const int table_size_y = 15;



int main()
{
    srand(time(0));
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Minesweeper", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    // Создаём текстуру и проверяем не загружена ли она
    sf::Texture texture;
    if (!texture.loadFromFile("./minesweeper.png"))
    {
        std::cout << "Can't load minesweeper.png texture" << std::endl;
        exit(1);
    }

    // Создаём спрайт
    sf::Sprite sprite(texture);
    // Задаём начальную позицию спрайта и позицию на текстуре
    sprite.setPosition(sf::Vector2f(100, 300));
    sprite.setTextureRect(sf::IntRect(1, 52, 16, 16));

    std::vector<int> table;
    table.resize(table_size_x*table_size_y);
    for (int i = 0; i < table_size_x; i++)
            for (int j = 0; j < table_size_y; j++)
                table[i + j*table_size_x] = rand() % 4;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int cell_x = (event.mouseButton.x - start_x) / cell_size;
                    int cell_y = (event.mouseButton.y - start_y) / cell_size;
                    if (cell_x >= 0 && cell_x < table_size_x && cell_y >= 0 && cell_y < table_size_y)
                        table[cell_x + cell_y*table_size_x] = (table[cell_x+cell_y*table_size_x] + 1) % 5;
                }
            }
        }


        window.clear(sf::Color::Black);

        for (int i = 0; i < table_size_x; i++)
            for (int j = 0; j < table_size_y; j++)
            {
                sprite.setPosition(sf::Vector2f(start_x + cell_size * i, start_y + cell_size * j));
                if (table[i + j*table_size_x] == 0)
                    sprite.setTextureRect(sf::IntRect(1, 52, cell_size, cell_size));
                else if (table[i+j*table_size_x] == 1)
                    sprite.setTextureRect(sf::IntRect(18, 52, cell_size, cell_size));
                else if (table[i+j*table_size_x] == 2)
                    sprite.setTextureRect(sf::IntRect(35, 52, cell_size, cell_size));
                else if (table[i+j*table_size_x] == 3)
                    sprite.setTextureRect(sf::IntRect(87, 52, cell_size, cell_size));
                else if (table[i+j*table_size_x] == 4)
                    sprite.setTextureRect(sf::IntRect(104, 52, cell_size, cell_size));
                window.draw(sprite);
            }
        window.display();
    }

    return 0;
}