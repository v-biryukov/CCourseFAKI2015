#pragma once
#include <stdlib.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include "base.h"
#include "player.h"
#include "skeleton.h"
#include "ghost.h"


class Game
{
private:
    int num_of_tiles_x;
    int num_of_tiles_y;

    sf::Texture tile_set;
    sf::Sprite tile;
    std::string* tile_map;

    std::vector<sf::Texture> background_textures;
    std::vector<sf::Sprite> backgrounds;

    float total_time;
    sf::Texture hero_tiles;
    sf::Texture skeleton_tiles;
    sf::Texture ghost_tiles;

    std::vector<Actor*> actors;
    Screen screen;
public:

    Game(int w, int h, std::string* start_tile_map):
            num_of_tiles_x(h), num_of_tiles_y(w), tile_map(start_tile_map), screen(0, 0)
    {
        total_time = 0;
        if (!tile_set.loadFromFile(graphics_path + "Foreground/Tileset.png"))
        {
            exit(1);
        }
        tile = sf::Sprite(tile_set);


        background_textures.resize(4);
        backgrounds.resize(4);
        background_textures[0].loadFromFile(graphics_path + "Background/CloudsBack.png");
        background_textures[1].loadFromFile(graphics_path + "Background/CloudsFront.png");
        background_textures[2].loadFromFile(graphics_path + "Background/BGBack.png");
        background_textures[3].loadFromFile(graphics_path + "Background/BGFront.png");
        for (int i = 0; i < 4; ++i)
        {
            background_textures[i].setRepeated(true);
            backgrounds[i] = sf::Sprite(background_textures[i]);
        }


        if (!hero_tiles.loadFromFile(graphics_path + "hero.png"))
        {
            exit(1);
        }
        if (!skeleton_tiles.loadFromFile(graphics_path + "Creatures/skeleton.png"))
        {
            exit(1);
        }
        if (!ghost_tiles.loadFromFile(graphics_path + "Creatures/ghost.png"))
        {
            exit(1);
        }

        
        Actor* hero = new Player(0, 0, hero_tiles, {12, 8, 2}, {{0, 0, 19, 34}, {0, 64, 21, 34}, {0, 192, 20, 34}});
        actors.push_back(hero);

        for (int i = 0; i < 0; ++i)
        {
            Actor* skeleton = new Skeleton(600, 250, skeleton_tiles, {4}, {{0, 0, 16, 16}});
            actors.push_back(skeleton);
        }

        for (int i = 0; i < 10; ++i)
        {
            Actor* ghost = new Ghost(600, 150, ghost_tiles, {3}, {{0, 0, 16, 16}});
            actors.push_back(ghost);
        }
    }

    ~Game()
    {
        for (std::vector<Actor*>::iterator it = actors.begin(); it != actors.end(); ++it)
        {
            delete *it;
        }
    }

    void set_player_position(float x, float y)
    {
        actors[0]->set_x(x);
        actors[0]->set_y(y);
    }

    void update(float time)
    {
        backgrounds[1].setTextureRect(sf::IntRect(total_time/3, 0, window_width, window_height));
        backgrounds[2].setTextureRect(sf::IntRect(screen.offset_x/100, 0, window_width, window_height));
        backgrounds[3].setTextureRect(sf::IntRect(screen.offset_x/30, 0, window_width, window_height));
        for (int i = 0; i < actors.size(); ++i)
        {
            actors[i]->update(time, tile_map, screen);
        }
        total_time += time;
    }


    void draw(sf::RenderWindow& window)
    {
        for (int i = 0; i < 4; ++i)
        {
            window.draw(backgrounds[i]);
        }
        for (int i=0; i<num_of_tiles_y; i++)
        {
            for (int j=0; j<num_of_tiles_x; j++)
            { 
                tile.setPosition(j*tile_size - screen.offset_x, i*tile_size - screen.offset_y); 
                // Рисуем блоки
                if (tile_map[i][j]=='q' || tile_map[i][j]=='Q')      tile.setTextureRect( sf::IntRect( 0,  0, 16, 16) );
                if (tile_map[i][j]=='w' || tile_map[i][j]=='W')      tile.setTextureRect( sf::IntRect(16,  0, 16, 16) );
                if (tile_map[i][j]=='e' || tile_map[i][j]=='E')      tile.setTextureRect( sf::IntRect(32,  0, 16, 16) );
                if (tile_map[i][j]=='a')                             tile.setTextureRect( sf::IntRect( 0, 16, 16, 16) );
                if (tile_map[i][j]=='s')                             tile.setTextureRect( sf::IntRect(16, 16, 16, 16) );
                if (tile_map[i][j]=='d')                             tile.setTextureRect( sf::IntRect(32, 16, 16, 16) );
                if (tile_map[i][j]=='z')                             tile.setTextureRect( sf::IntRect( 0, 32, 16, 16) );
                if (tile_map[i][j]=='x')                             tile.setTextureRect( sf::IntRect(16, 32, 16, 16) );
                if (tile_map[i][j]=='c')                             tile.setTextureRect( sf::IntRect(32, 32, 16, 16) );
                if (tile_map[i][j]=='r'  || tile_map[i][j]=='R')     tile.setTextureRect( sf::IntRect(48,  0, 16, 16) );
                if (tile_map[i][j]=='t')                             tile.setTextureRect( sf::IntRect(64,  0, 16, 16) );
                if (tile_map[i][j]=='y')                             tile.setTextureRect( sf::IntRect(80,  0, 16, 16) );
                if (tile_map[i][j]=='u')                             tile.setTextureRect( sf::IntRect(96,  0, 16, 16) );
                if (tile_map[i][j]=='U')                             tile.setTextureRect( sf::IntRect(112, 0,-16 ,16) );
                if (tile_map[i][j]=='i')                             tile.setTextureRect( sf::IntRect(112, 0, 16, 16) );
                if (tile_map[i][j]=='f')                             tile.setTextureRect( sf::IntRect(48, 16, 16, 16) );
                if (tile_map[i][j]=='g')                             tile.setTextureRect( sf::IntRect(64, 16, 16, 16) );
                if (tile_map[i][j]=='h')                             tile.setTextureRect( sf::IntRect(80, 16, 16, 16) );
                if (tile_map[i][j]=='v')                             tile.setTextureRect( sf::IntRect(48, 32, 16, 16) );
                if (tile_map[i][j]=='b')                             tile.setTextureRect( sf::IntRect(112, 64, 16, 16) );
                if ((tile_map[i][j]==' ') || (tile_map[i][j]=='0'))   continue;
                window.draw(tile);

                // Рисуем траву
                if (tile_map[i][j]=='W')                             tile.setTextureRect( sf::IntRect(112, 32, 16, 16) );
                if (tile_map[i][j]=='R')                             tile.setTextureRect( sf::IntRect(128, 32, 16, 16) );
                if (tile_map[i][j]=='Q')                             tile.setTextureRect( sf::IntRect(96, 32, 16, 16) );
                if (tile_map[i][j]=='E')                             tile.setTextureRect( sf::IntRect(144, 32, 16, 16) );
                window.draw(tile);

            }
        }
        for (int i = 0; i < actors.size(); ++i)
        {
            actors[i]->draw(window);
        }
    }
};
