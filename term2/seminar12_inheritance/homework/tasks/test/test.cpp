#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


// Создадим класс монстра
class Monster
{
protected:
    const int floor_y_coordinate = 550;

    // Текстура и спрайт для отрисовки
    sf::Texture& texture;
    sf::Sprite sprite;

    // Положение и скорость
    sf::Vector2f position;
    sf::Vector2f velocity;

    // Направление движения (-1 или +1)
    int direction;
    // Скорость движения
    float speed;

    // Здоровье и булевая переменная (жив или нет)
    int health;
    bool is_alive;

    // Параметры для анимации (положение прямоугольника на текстуре)
    sf::Vector2i texture_rect_position;
    sf::Vector2i texture_rect_size;

    // Количество кадров в анимации
    int number_of_frames;
    // Скорость анимации
    float animation_speed;
    // Текущий кадр анимации
    float current_frame;

public:
    Monster(sf::Texture& texture, sf::Vector2f position, sf::Vector2f velocity = {0, 0}) 
            : texture(texture), position(position), velocity(velocity)
    {
        sprite.setTexture(texture);
        sprite.setTextureRect({0, 0, 20, 34});
        sprite.setOrigin(sprite.getTextureRect().width/2, sprite.getTextureRect().height/2);
        sprite.setScale(sf::Vector2f(2.8, 2.8));

        sprite.setPosition(position);

        health = 100;
        is_alive = false;
        speed = 100;

        direction = 1;
        current_frame = rand() % number_of_frames;
    }

    void set_animation_parameters(sf::Vector2i texture_rect_position_in, sf::Vector2i texture_rect_size_in, 
                                  int number_of_frames_in, float animation_speed_in)
    {
        texture_rect_position = texture_rect_position_in;
        texture_rect_size = texture_rect_size_in;
        number_of_frames = number_of_frames_in;
        animation_speed = animation_speed_in;
    }

    void hurt(int damage)
    {
        health -= damage;
        if (health <= 0)
            is_alive = false;
    }

    void heal(int heal_power)
    {
        if (is_alive)
            health += heal_power;
        if (health > 100)
            health = 100;
    }

    void walk(float dt)
    {
        if (position.x > 1000)
        {
            position.x = 1000;
            direction = -1;
        }
        if (position.x < 0)
        {
            position.x = 0;
            direction = 1;
        }
        velocity.x = speed * direction;


        if (sprite.getPosition().y + sprite.getLocalBounds().height > floor_y_coordinate)
        {
            velocity.y = 0;
        }
        else
        {
            velocity.y += 20;
        }

        position += velocity * dt;
        sprite.setPosition(position);

        current_frame += animation_speed * dt;
        if (current_frame > number_of_frames)
            current_frame -= number_of_frames;
        if (direction == 1)
        {
            sprite.setTextureRect({texture_rect_size.x * (int)current_frame , 0, texture_rect_size.x, texture_rect_size.y});
        }
        else if (direction == -1)
        {
            sprite.setTextureRect({texture_rect_size.x * ((int)current_frame + 1), 0, -texture_rect_size.x, texture_rect_size.y});
        }
    }


    void draw(sf::RenderWindow& window)
    {
        window.draw(sprite);
    }
};



int main () 
{
    const int window_width = 1200;
    const int window_height = 600;

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Monsters");
    window.setFramerateLimit(60);

    sf::Texture background_texture;
    background_texture.loadFromFile("../images/backgrounds/background_hill.png");
    sf::Sprite background(background_texture);
    background.setScale((float)window_width / background.getLocalBounds().width, (float)window_height / background.getLocalBounds().height);

    sf::Texture monster_texture;
    
    monster_texture.loadFromFile("../images/skeleton_walk.png");
    //monster_texture.loadFromFile("../images/ghost.png");
    //monster_texture.loadFromFile("../images/ninja_walk.png");

    Monster a(monster_texture, {100, 300});
    a.set_animation_parameters({0, 0}, {22, 34}, 13, 50.0);
    //a.set_animation_parameters({0, 0}, {16, 16}, 3, 4.0);
    //a.set_animation_parameters({0, 0}, {32, 26}, 6, 10.0);

    while (window.isOpen()) 
    {
        sf::Event event;
        while(window.pollEvent(event)) 
        {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {

                }

            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::M)
                {
                    std::cout << "the M key was pressed" << std::endl;
                }
            }

        }

        window.draw(background);
        // Двигаем на dt
        a.walk(1.0/60);
        

        // Рисуем
        a.draw(window);

        window.display();
    }

    return EXIT_SUCCESS;
}