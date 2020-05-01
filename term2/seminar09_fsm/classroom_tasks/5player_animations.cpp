#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Animation
{
private:
	sf::IntRect texture_rect;

	int number_of_frames;
	float animation_speed;

	float time;

public:
	Animation(sf::IntRect texture_rect, int number_of_frames, float animation_speed) :
			  number_of_frames(number_of_frames), animation_speed(animation_speed), texture_rect(texture_rect)
	{
		
	}

	void update(float dt)
	{
		time += dt;
		if (time > number_of_frames / animation_speed)
			time -= number_of_frames / animation_speed;
	}

	void set_sprite(sf::Sprite& sprite, bool is_faced_right)
	{
		int current_frame = (int)(animation_speed * time) % number_of_frames;
		if (is_faced_right)
		{
			texture_rect.left = current_frame * texture_rect.width;
			sprite.setTextureRect(texture_rect);
		}
		else
		{
			texture_rect.left = (current_frame + 1) * texture_rect.width;
			texture_rect.width *= -1;
			sprite.setTextureRect(texture_rect);
			texture_rect.width *= -1;
		}
	}
};


int main () 
{
	sf::RenderWindow window(sf::VideoMode(1200, 900), "Player states");
	window.setFramerateLimit(60);

	// Создаём и открываем текстуру
	sf::Texture player_texture;
	if (!player_texture.loadFromFile("./hero.png"))
	{
		std::cout << "Can't load image ./hero.png" << std::endl;
		exit(1);
	}

	sf::Texture explosion_texture;
	if (!explosion_texture.loadFromFile("./explosion.png"))
	{
		std::cout << "Can't load image ./explosion.png" << std::endl;
		exit(1);
	}

	sf::Sprite player_sprite;
	player_sprite.setTexture(player_texture);
	player_sprite.setScale(4, 4);

	sf::Sprite explosion_sprite;
	explosion_sprite.setTexture(explosion_texture);
	explosion_sprite.setScale(2, 2);

	Animation animation_running({0, 64, 21, 34}, 8, 12);
	Animation animation_hooked({0, 118, 20, 50}, 6, 12);
	Animation animation_idle({0, 0, 19, 34}, 12, 12);
	Animation animation_explode({0, 0, 96, 96}, 12, 10);

	float time = 0;
	float dt = 1.0 / 60;
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
		window.clear(sf::Color::Black);
		
		animation_running.update(dt);
		animation_idle.update(dt);
		animation_hooked.update(dt);
		animation_explode.update(dt);
		
		player_sprite.setPosition({450, 300});
		animation_running.set_sprite(player_sprite, true);
		window.draw(player_sprite);

		player_sprite.setPosition({200, 100});
		animation_running.set_sprite(player_sprite, false);
		window.draw(player_sprite);

		player_sprite.setPosition({100, 300});
		animation_idle.set_sprite(player_sprite, true);
		window.draw(player_sprite);

		player_sprite.setPosition({200, 300});
		animation_idle.set_sprite(player_sprite, false);
		window.draw(player_sprite);

		player_sprite.setPosition({100, 500});
		animation_hooked.set_sprite(player_sprite, true);
		window.draw(player_sprite);

		player_sprite.setPosition({200, 500});
		animation_hooked.set_sprite(player_sprite, false);
		window.draw(player_sprite);

		explosion_sprite.setPosition({400, 300});
		animation_explode.set_sprite(explosion_sprite, true);
		window.draw(explosion_sprite);

		window.display();
		time += dt;
	}

	return EXIT_SUCCESS;
}


/*
	Задание:
	Найти спрайтовую анимацию в интернете и нарисовать её.
	Можно просто загуглить "sprites"
*/