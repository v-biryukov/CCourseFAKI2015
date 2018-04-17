#pragma once
#include <stdlib.h>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "base.h"
#include "actor.h"


const float skeleton_speed = 5;
const float skeleton_jump = 25;

class Skeleton : public Actor
{
private:

public:
    Skeleton() : Actor() {}
    Skeleton(float x0, float y0, const sf::Texture& texture, 
        std::vector<int> init_num_of_frames, std::vector<AnimationBox> init_anim_boxes) : 
        Actor(x0, y0, texture, init_num_of_frames, init_anim_boxes)
    {
    }

    void update(float time, const std::string* tile_map, Screen& screen)
    {
        if (rand() % 1000 < 5)
            direction *= -1;

        if (rand() % 1000 < 5)
        {
            vy -= skeleton_jump; 
        }
        vx = direction*skeleton_speed;
        x += vx*time;
        handle_collision(tile_map, 0);
        vy += gravity_acceleration * time;
        y += vy*time;
        handle_collision(tile_map, 1);
        current_frame += time;

        set_sprite();
        sprite.setPosition(x - screen.offset_x, y - screen.offset_y);
    }
};