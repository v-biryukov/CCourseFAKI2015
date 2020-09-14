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
	Animation() {}

	Animation(sf::IntRect texture_rect, int number_of_frames, float animation_speed) :
			  number_of_frames(number_of_frames), animation_speed(animation_speed), texture_rect(texture_rect),
			  time(0)
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


class Player;

class PlayerState
{
protected:
	Animation animation;
public:
	PlayerState()
	{
	}
	virtual void start_running(Player* sm) = 0;
	virtual void stop(Player* sm) = 0;
	void update(float dt)
	{
		animation.update(dt);
	}
	void set_sprite(sf::Sprite& sprite, int direction)
	{
		animation.set_sprite(sprite, direction);
	}
	virtual ~PlayerState() {};
};

class Idle : public PlayerState
{
public:
	Idle()
	{
		animation = Animation({0, 0, 19, 34}, 12, 12);
		cout << "Creating Idle state" << endl;
	}
	void start_running(Player* player);
	void stop(Player* player);
};

class Running : public PlayerState
{
public:
	Running()
	{
		animation = Animation({0, 64, 21, 34}, 8, 12);
		cout << "Creating Running state" << endl;
	}
	void start_running(Player* player);
	void stop(Player* player);
};


class Player
{
private:
	PlayerState* state;
	
	sf::Texture texture;
	sf::Sprite sprite;

	bool is_faced_right;
	sf::Vector2f velocity;
	float speed;

	void set_state(PlayerState* new_state)
	{
		delete state;
		state = new_state;
	}

public:
	Player(sf::Vector2f position = {0, 0})
	{
		if (!texture.loadFromFile("./hero.png"))
		{
			std::cout << "Can't load image ./hero.png for Player class" << std::endl;
			exit(1);
		}
		sprite.setTexture(texture);
		sprite.setPosition(position);
		sprite.setScale(5, 5);
		state = new Idle();
		speed = 500.0;
	}

	void update(float dt)
	{
		state->update(dt);
		velocity = {0, 0};

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			velocity.x -= speed;
			is_faced_right = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			velocity.x += speed;
			is_faced_right = true;
		}
		sprite.setPosition(sprite.getPosition() + velocity * dt);
	}

	void draw(sf::RenderWindow& window)
	{
		state->set_sprite(sprite, is_faced_right);
		window.draw(sprite);
	}


	void handle_events(const sf::Event& event) 
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
			{
				state->start_running(this);
			}
		}
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Left && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				state->stop(this);
			}
			if (event.key.code == sf::Keyboard::Right && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				state->stop(this);
			}
		}
	}

	~Player()
	{
		delete state;
	}

	friend class PlayerState;
	friend class Idle;
	friend class Running;
};


void Idle::start_running(Player* player)
{
	player->set_state(new Running());
}

void Idle::stop(Player* player)
{
}

void Running::start_running(Player* player)
{
}

void Running::stop(Player* player)
{
	player->set_state(new Idle());
}






int main () 
{
	sf::RenderWindow window(sf::VideoMode(1200, 900), "Player states");
	window.setFramerateLimit(60);

	float time = 0;
	float dt = 1.0 / 60;

	Player player({400, 400});

	while (window.isOpen()) 
	{
		sf::Event event;
		while(window.pollEvent(event)) 
		{
			if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
			{
				window.close();
			}
			player.handle_events(event);
		}
		window.clear(sf::Color::Black);

		player.update(dt);
		player.draw(window);

		window.display();

		time += 1.0 / 60;
	}

	return EXIT_SUCCESS;
}



/*
	Задания:
		1) Добавить остальные состояния. Они должны правильно отрисововаться.
		   При этом понадобится внести изменения и в класс Player.
		   Например, для состояния Jumping нужно будет добавить гравитацию
		2) Добавить background.png на экран. 
		   Персонаж должен правильно взаимодействовать с окружением.
		   Это проще всего сделать введя новый класс World или Game, который будет содержать
		   					экземпляр Player, а так же остальные параметры мира.

*/