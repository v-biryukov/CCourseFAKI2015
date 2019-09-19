#pragma once
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "base.h"
#include "actor.h"


const float ghost_speed = 2;

class Ghost : public Actor
{
private:

    void set_random_velocity()
    {
        vx = (rand() % 1999 - 999) * ghost_speed / 1000;
        vy = (2*(rand()%2) - 1)*sqrt(ghost_speed*ghost_speed - vx*vx);
        direction = vx < 0 ? -1 : 1;
    }

public:
    Ghost() : Actor() {}
    Ghost(float x0, float y0, const sf::Texture& texture, 
        std::vector<int> init_num_of_frames, std::vector<AnimationBox> init_anim_boxes) : 
        Actor(x0, y0, texture, init_num_of_frames, init_anim_boxes)
    {
        set_random_velocity();
    }

    void update(float time, std::string* tile_map, Screen& screen)
    {
        if (rand() % 1000 < 50)
            set_random_velocity();

        x += vx*time;
        handle_collision(tile_map, 0);
        y += vy*time;
        handle_collision(tile_map, 1);
        current_frame += time;

        set_sprite();
        sprite.setPosition(x - screen.offset_x, y - screen.offset_y);
    }
};