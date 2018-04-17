#pragma once
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "base.h"
#include "actor.h"

const float player_speed = 20;
const float player_jump = 45;

class Player : public Actor
{
private:
    int health;

public:
    Player() : Actor() {}
    Player(float x0, float y0, const sf::Texture& texture, 
        std::vector<int> init_num_of_frames, std::vector<AnimationBox> init_anim_boxes) : 
        Actor(x0, y0, texture, init_num_of_frames, init_anim_boxes)
    {
    }

    void update(float time, std::string* tile_map, Screen& screen)
    {
        x += vx*time;
        handle_collision(tile_map, 0);
        vy += gravity_acceleration * time;
        y += vy*time;
        handle_collision(tile_map, 1);
        current_frame += time;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))  
        {
            if (state != FALLING)
            {
                vy -= player_jump; 
                state = FALLING;
            }   
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (state == IDLE)
            {
                state = RUNNING;
            }
            vx = -player_speed;
            direction = -1;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))  
        {  
            if (state == IDLE)
            {
                state = RUNNING;
            }
            vx = player_speed;
            direction = 1;
        }
        else
        {
            if (state != FALLING)
            {
                state = IDLE;
                vx = 0;
            }
        }
        set_sprite();
        sprite.setPosition(x - screen.offset_x, y - screen.offset_y);
        screen.offset_x = x - window_width / 2;
        screen.offset_y = y - window_height / 1.5;
    }

};