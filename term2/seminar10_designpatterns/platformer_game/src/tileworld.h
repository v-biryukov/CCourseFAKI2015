#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>

#include "player.h"
#include "player_states.h"

#include "tiles.h"




class TileWorld
{
private:

	int num_tiles_x, num_tiles_y;
	int tilesize;
	
	sf::Texture tileset_texture;
	std::map<Tile, sf::IntRect> tile_texture_coords;

	// Сетка из ячеек (тайлов) (вектора tilegrid и decoration_tilegrid имеют размер num_tiles_x * num_tiles_y)
	// tilegrid            - непроходимые тайлы
	// decoration_tilegrid - проходимые декоративные тайлы
	std::vector<Tile> tilegrid;
	std::vector<Tile> decoration_tilegrid;

	Player player;

	sf::Sprite tile_sprite;

	sf::View view;

	std::vector<sf::Texture> background_textures;
    std::vector<sf::Sprite> backgrounds;

	float time;
	float scale_factor;

	bool is_editor_mode;

public:

	TileWorld(unsigned int num_tiles_x, unsigned int num_tiles_y) 
		: num_tiles_x(num_tiles_x), num_tiles_y(num_tiles_y), player(Player({540, 540})), view(sf::FloatRect(0, 0, 1200, 900)), time(0)
	{

		background_textures.resize(4);
        backgrounds.resize(4);
        background_textures[0].loadFromFile("../textures/background/CloudsBack.png");
        background_textures[1].loadFromFile("../textures/background/CloudsFront.png");
        background_textures[2].loadFromFile("../textures/background/BGBack.png");
        background_textures[3].loadFromFile("../textures/background/BGFront.png");
        for (int i = 0; i < 4; ++i)
        {
            background_textures[i].setRepeated(true);
            backgrounds[i] = sf::Sprite(background_textures[i]);
            backgrounds[i].setScale(3, 3);
        }

		tilesize = 16;
		if (!tileset_texture.loadFromFile("../textures/tileset.png"))
		{
			std::cout << "Can't load image ../textures/tileset.png for TileWorld class" << std::endl;
			exit(1);
		}
		tile_sprite.setTexture(tileset_texture);
		scale_factor = 5;
		tile_sprite.setScale(scale_factor, scale_factor);


		tile_texture_coords = {
			{Tile::TransparentWall, {64, 32, 16, 16}},
			{Tile::GroundTopLeft, {0, 0, 16, 16}},    
			{Tile::GroundTop, {16, 0, 16, 16}},     
			{Tile::GroundTopRight, {32, 0, 16, 16}},
			{Tile::GroundLeft, {0, 16, 16, 16}},       
			{Tile::GroundCenter, {16, 16, 16, 16}},  
			{Tile::GroundRight, {32, 16, 16, 16}},
			{Tile::GroundBottomLeft, {0, 32, 16, 16}}, 
			{Tile::GroundBottom, {16, 32, 16, 16}},  
			{Tile::GroundBottomRight, {32, 32, 16, 16}},
			{Tile::GroundTop2, {48, 0, 16, 16}},
			{Tile::InnerStones, {48, 16, 16, 16}},
			{Tile::InnerStones2, {48, 32, 16, 16}},
			{Tile::GroundCornerBottomRight, {96, 0, 16, 16}},
			{Tile::GroundCornerBottomLeft, {112, 0, 16, 16}},
			{Tile::Tablet, {112, 0, 16, 16}},
			{Tile::GrassLeft, {96, 32, 16, 16}},       
			{Tile::GrassCenter, {112, 32, 16, 16}},  
			{Tile::GrassRight, {128, 32, 16, 16}}
		};



		tilegrid.resize(num_tiles_x * num_tiles_y);

		for (int i = 0; i < num_tiles_x * num_tiles_y; i++)
			tilegrid[i] = Tile::GroundCenter;
		for (int i = 4; i < num_tiles_x - 4; i++)
			for (int j = 4; j < num_tiles_y - 4; j++)
				tilegrid[i + num_tiles_x * j] = Tile::None;

		for (int i = 4; i < num_tiles_x - 4; i++)
		{
			for (int j = 4; j < num_tiles_y - 4; j++)
			{
				if (rand() % 100 < 2)
				{
					tilegrid[i + num_tiles_x * j] = Tile::GroundTop;
				}
			}
		}

		decoration_tilegrid.resize(num_tiles_x * num_tiles_y);
		for (int i = 4; i < num_tiles_x - 4; i++)
		{
			for (int j = 4; j < num_tiles_y - 4; j++)
			{
				if (rand() % 100 < 2)
				{
					decoration_tilegrid[i + num_tiles_x * j] = Tile::GrassRight;
				}
				if (rand() % 100 < 2)
				{
					decoration_tilegrid[i + num_tiles_x * j] = Tile::GrassCenter;
				}
				if (rand() % 100 < 2)
				{
					decoration_tilegrid[i + num_tiles_x * j] = Tile::GrassLeft;
				}
			}
		}
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

	void update_backgrounds()
	{
		backgrounds[1].setTextureRect(sf::IntRect(20 * time, 0, 1200, 900));
		backgrounds[0].setTextureRect(sf::IntRect(40 * time, 0, 1200, 900));
	}

	void update(float dt)
	{	
		time += dt;
		set_view();
		update_backgrounds();
		player.update(dt);
		player.handle_all_collisions({num_tiles_x, num_tiles_y}, {(int)(tilesize * scale_factor), (int)(tilesize * scale_factor)}, tilegrid);
	}

	void draw(sf::RenderWindow& window)
	{
		window.setView(window.getDefaultView());

		for (int i = 0; i < 4; ++i)
        {
            window.draw(backgrounds[i]);
        }
        window.setView(view);
		for (int i = 0; i < num_tiles_x; i++)
			for (int j = 0; j < num_tiles_y; j++)
			{
				tile_sprite.setPosition(tilesize * scale_factor * i, tilesize * scale_factor * j);
				tile_sprite.setTextureRect(tile_texture_coords[tilegrid[i + j * num_tiles_x]]);
				window.draw(tile_sprite);
				tile_sprite.setTextureRect(tile_texture_coords[decoration_tilegrid[i + j * num_tiles_x]]);
				window.draw(tile_sprite);
			}
		player.draw(window);
	}

	void handle_events(const sf::RenderWindow& window, const sf::Event& event)
	{
		player.handle_events(event);

		if (event.type == sf::Event::MouseButtonPressed)
		{
			sf::Vector2i pixel_pos = sf::Mouse::getPosition(window);
			sf::Vector2f world_pos = window.mapPixelToCoords(pixel_pos) / (tilesize * scale_factor);
			sf::Vector2i tile_pos = {(int)world_pos.x, (int)world_pos.y};
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				tilegrid[tile_pos.x + num_tiles_x * tile_pos.y] = (Tile)((int)tilegrid[tile_pos.x + num_tiles_x * tile_pos.y] + 1);
			}
			if (event.mouseButton.button == sf::Mouse::Right)
			{
				tilegrid[tile_pos.x + num_tiles_x * tile_pos.y] = Tile::None;
			}
		}
	}


	void save_to_file(std::string filename)
	{
		std::ofstream savefile;
		savefile.open(filename);
		savefile << num_tiles_x << " " << num_tiles_y << std::endl;
		
		for (int j = 0; j < num_tiles_y; j++)
		{
			for (int i = 0; i < num_tiles_x; i++)
			{
				savefile.width(2);
				savefile << (int)tilegrid[i + num_tiles_x * j] << " ";
			}
			savefile << std::endl;
		}

		for (int j = 0; j < num_tiles_y; j++)
		{
			for (int i = 0; i < num_tiles_x; i++)
			{
				savefile.width(2);
				savefile << (int)decoration_tilegrid[i + num_tiles_x * j] << " ";
			}
			savefile << std::endl;
		}
		savefile.close();
	}

	void load_from_file(std::string filename)
	{
		std::ifstream loadfile;
		loadfile.open(filename);
		loadfile >> num_tiles_x >> num_tiles_y;
		tilegrid.resize(num_tiles_x * num_tiles_y);
		for (int j = 0; j < num_tiles_y; j++)
		{
			for (int i = 0; i < num_tiles_x; i++)
			{
				int temp;
				loadfile >> temp;
				tilegrid[i + num_tiles_x * j] = (Tile)temp;
			}
		}
		decoration_tilegrid.resize(num_tiles_x * num_tiles_y);
		for (int j = 0; j < num_tiles_y; j++)
		{
			for (int i = 0; i < num_tiles_x; i++)
			{
				int temp;
				loadfile >> temp;
				decoration_tilegrid[i + num_tiles_x * j] = (Tile)temp;
			}
		}
		loadfile.close();
	}
};