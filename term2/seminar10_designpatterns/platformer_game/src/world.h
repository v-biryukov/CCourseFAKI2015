#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "player.h"
#include "player_states.h"




class World
{
private:
	Player player;

	std::vector<sf::FloatRect> blocks;
	sf::RectangleShape block_shape;

	sf::View view;

	float time;

public:

	World() : player(Player({400, 400})), view(sf::FloatRect(0, 0, 1200, 900)), time(0)
	{
		block_shape.setFillColor(sf::Color(58, 69, 55));
	}

	void add_block(sf::FloatRect block)
	{
		blocks.push_back(block);
	}

	void set_view()
	{
		sf::Vector2f player_center = player.get_center();
		float view_move_ratio = 0.6;
		if (player_center.x > view.getCenter().x + view_move_ratio * view.getSize().x / 2)
		{
			view.move({player_center.x - view.getCenter().x - view_move_ratio * view.getSize().x / 2, 0});
		}
		else if (player_center.x < view.getCenter().x - view_move_ratio * view.getSize().x / 2)
		{
			view.move({player_center.x - view.getCenter().x + view_move_ratio * view.getSize().x / 2, 0});
		}

		if (player_center.y > view.getCenter().y + view_move_ratio * view.getSize().y / 2)
		{
			view.move({0, player_center.y - view.getCenter().y - view_move_ratio * view.getSize().y / 2});
		}
		else if (player_center.y < view.getCenter().y - view_move_ratio * view.getSize().y / 2)
		{
			view.move({0, player_center.y - view.getCenter().y+ view_move_ratio * view.getSize().y / 2});
		}

	}

	void update(float dt)
	{	
		time += dt;
		set_view();
		player.update(dt);
		player.handle_all_collisions(blocks);

	}

	void draw(sf::RenderWindow& window)
	{
		window.setView(view);

		for (const sf::FloatRect& block_rect: blocks)
		{
			block_shape.setPosition(block_rect.left, block_rect.top);
			block_shape.setSize({(float)block_rect.width, (float)block_rect.height});
			window.draw(block_shape);
		}
		player.draw(window);
	}

	void handle_events(const sf::Event& event)
	{
		player.handle_events(event);
	}
};