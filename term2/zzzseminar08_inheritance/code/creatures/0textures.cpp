#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main () 
{

    sf::RenderWindow window(sf::VideoMode(1200, 900), "Creatures");
    window.setFramerateLimit(60);

    // Создаём текстуру и проверяем не загружена ли она
    sf::Texture texture;
    if (!texture.loadFromFile("./images/monster.png"))
    {
        exit(1);
    }

    // Создаём спрайт
    sf::Sprite sprite(texture);
    // Устанавливаем центр спрайта (точка, вокруг которой он будет вращаться)
    sprite.setOrigin(sprite.getTextureRect().width/2, sprite.getTextureRect().height/2);
    // Задаём размер и начальную позицию спрайта
    sprite.setScale(sf::Vector2f(0.2, 0.2));
    sprite.setPosition(sf::Vector2f(100, 300));

    while (window.isOpen()) 
    {
        sf::Event event;
        while(window.pollEvent(event)) 
        {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
            {
                window.close();
            }

        }

        window.clear();

        // Двигаем на 1 пиксель вправо каждый кадр
        sprite.move(1, 0);
        // Вращаем на 1 градус каждый кадр
        sprite.rotate(1);
        window.draw(sprite);

        window.display();
    }

    return EXIT_SUCCESS;
}