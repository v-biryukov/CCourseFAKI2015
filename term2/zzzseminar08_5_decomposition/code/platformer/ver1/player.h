#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "base.h"


enum PlayereState {IDLE, RUNNING, FALLING};
struct AnimationBox
{
    int offset_x, offset_y;
    int width, height;
};
const int player_animation_num_of_frames[3] = {12, 8, 2};
const AnimationBox player_animation_boxes[3] = {{0, 0, 19, 34}, {0, 64, 21, 34}, {0, 192, 20, 34}};
const float player_speed = 20;
const float player_jump = 45;

class Player
{
private:
    int health;
    float x, y;
    float width, height;
    float vx, vy;
    int direction;
    sf::Sprite sprite;
    float current_frame;

    PlayereState state;


    void set_sprite()
    {
        if (current_frame > player_animation_num_of_frames[state])
            current_frame -= player_animation_num_of_frames[state];
        width = player_animation_boxes[state].width;
        height = player_animation_boxes[state].height;
        if (direction == 1)
        {
            sprite.setTextureRect(sf::IntRect(player_animation_boxes[state].offset_x + width*int(current_frame), 
                              player_animation_boxes[state].offset_y, 
                              width, height));
        }
        else
        {
            sprite.setTextureRect(sf::IntRect(player_animation_boxes[state].offset_x + width*int(current_frame) + width, 
                                  player_animation_boxes[state].offset_y, 
                                  -width, height));
        }
    }

public:
    Player() {}
    Player(float x0, float y0, const sf::Texture& texture): x(x0), y(y0)
    {
        sprite.setTexture(texture);
        vx = vy = 0;
        current_frame = 0.0f;
        state = IDLE;
        width = player_animation_boxes[state].width;
        height = player_animation_boxes[state].height;
        direction = 1;
    }

    void set_vx(float vx) { this->vx = vx;}
    void set_vy(float vy) { this->vy = vy;}

    void set_x(float x) { this->x = x;}
    void set_y(float y) { this->y = y;}
    float get_x() { return x;}
    float get_y() { return y;}



    void update(float time, const std::string* tile_map, Screen& screen)
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
                y -= 5;
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

    void handle_collision(const std::string* tile_map, int axis)
    {
        for (int i = x/tile_size; i < (x+width)/tile_size; i++)
            for (int j = y/tile_size; j < (y+height)/tile_size; j++)
            {
                if ((tile_map[j][i] != ' '))
                { 
                    if (vy > 0 && axis == 1)
                    { 
                        y = j*tile_size -  height;  
                        vy = 0;  
                        state = IDLE; 
                    }
                    if ((tile_map[j][i] != 'b'))
                    {
                        if (vy < 0 && axis == 1)
                        { 
                            y = j*tile_size + tile_size;   
                            vy = 0;
                        }
                        if (vx > 0 && axis == 0)
                        { 
                            x =  i*tile_size -  width; 
                        }
                        if (vx < 0 && axis == 0)
                        {
                            x =  i*tile_size + tile_size;
                        }
                    }
                }
            }
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(sprite);
    }
};