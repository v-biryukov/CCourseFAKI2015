#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "player_states.h"

class PlayerState;

class Player
{
private:
	PlayerState* state;
	
	sf::Texture texture;
	sf::Sprite sprite;

	bool is_faced_right;
	sf::Vector2f velocity;
	float scale_factor;

	const float jumping_velocity = 1400;
	void set_state(PlayerState* new_state);

public:
	Player(sf::Vector2f position);

	sf::Vector2f get_center() const;

	void update(float dt);
	void draw(sf::RenderWindow& window);
	void jump();
	void handle_events(const sf::Event& event);
	bool handle_collision(const sf::FloatRect& rect);
	void handle_all_collisions(const std::vector<sf::FloatRect>& blocks);


	~Player();

	friend class PlayerState;
	friend class Idle;
	friend class Running;
	friend class Falling;
	friend class Sliding;
	friend class Hooked;
};