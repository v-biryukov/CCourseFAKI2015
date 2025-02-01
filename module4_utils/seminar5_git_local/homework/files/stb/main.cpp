#include <iostream>
#include <vector>
#include "stb_image.h"
#include "stb_image_write.h"

int main()
{
    int width, height, channels;
    unsigned char* rawPixels = stbi_load("zlatoust1910.jpg", &width, &height, &channels, 0);

    int numberOfBytes = width * height * channels;
    std::vector<unsigned char> pixels(rawPixels, rawPixels + numberOfBytes);

    // Увеличим яркость каждого пикселя
    for (unsigned char& el : pixels)
    {
        int value = el;
        value += 50;
        if (value > 255)
            value = 255;
        el = value;
    }


    stbi_write_jpg("zlatoust1910_changed.jpg", width, height, channels, pixels.data(), 50);
}