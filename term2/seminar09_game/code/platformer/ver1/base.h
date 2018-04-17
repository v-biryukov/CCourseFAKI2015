#pragma once
#include <string>

const int window_width = 512;
const int window_height = 320;
const float gravity_acceleration = 10;
const int tile_size = 16;
const float time_speed = 0.00002;
const std::string graphics_path = "../graphics/";
struct Screen
{
    float offset_x, offset_y;
    Screen(float offset_x, float offset_y) : offset_x(offset_x), offset_y(offset_y){}
};
