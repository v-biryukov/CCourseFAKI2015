#pragma once
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "base.h"


enum ActorState {IDLE, RUNNING, FALLING};
struct AnimationBox
{
    int offset_x, offset_y;
    int width, height;
};

class Actor
{
protected:
    float x, y;
    float width, height;
    float vx, vy;
    int direction;
    sf::Sprite sprite;
    float current_frame;

    ActorState state;

    std::vector<int> animation_num_of_frames;
    std::vector<AnimationBox> animation_boxes;


    void set_sprite()
    {
        if (current_frame > animation_num_of_frames[state])
            current_frame -= animation_num_of_frames[state];
        width = animation_boxes[state].width;
        height = animation_boxes[state].height;
        if (direction == 1)
        {
            sprite.setTextureRect(sf::IntRect(animation_boxes[state].offset_x + width*int(current_frame), 
                              animation_boxes[state].offset_y, 
                              width, height));
        }
        else
        {
            sprite.setTextureRect(sf::IntRect(animation_boxes[state].offset_x + width*int(current_frame) + width, 
                                  animation_boxes[state].offset_y, 
                                  -width, height));
        }
    }

    void handle_collision(const std::string* tile_map, int axis)
    {
        for (int i = x/tile_size; i < (x+width)/tile_size; i++)
            for (int j = y/tile_size; j < (y+height)/tile_size; j++)
            {

                if (j > 40)
                    cout << i << " " << j << " " << x << " " << y << endl;
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


public:
    Actor() {}
    Actor(float x0, float y0, const sf::Texture& texture, 
        std::vector<int> init_num_of_frames, std::vector<AnimationBox> init_anim_boxes): x(x0), y(y0)
    {
        sprite.setTexture(texture);
        vx = vy = 0;
        current_frame = 0.0f;
        state = IDLE;
        direction = 1;

        int num_of_states = init_num_of_frames.size();
        animation_num_of_frames.resize(num_of_states);
        animation_boxes.resize(num_of_states);

        for (int i = 0; i < num_of_states; ++i)
        {
            animation_num_of_frames[i] = init_num_of_frames[i];
            animation_boxes[i] = init_anim_boxes[i];
        }

        width = animation_boxes[state].width;
        height = animation_boxes[state].height;
    }

    void set_vx(float vx) { this->vx = vx;}
    void set_vy(float vy) { this->vy = vy;}
    void set_x(float x) { this->x = x;}
    void set_y(float y) { this->y = y;}
    float get_x() { return x;}
    float get_y() { return y;}


    virtual void update(float time, const std::string* tile_map, Screen& screen) = 0;

    virtual void draw(sf::RenderWindow& window)
    {
        window.draw(sprite);
    }
};