#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main()
{
    int width, height, channels;
    unsigned char* img = stbi_load("russian_peasants.jpg", &width, &height, &channels, 0);
    
    if(img == NULL)
    {
         std::cout << "Error while loading image\n";
         exit(1);
    }

    std::cout << width << std::endl;
    std::cout << height << std::endl;
    std::cout << channels << std::endl;

    for (int i = 0; i < 100; ++i)
    {
        std::cout << std::hex << (int)img[i] << " ";
    }
    std::cout << std::endl;

    stbi_image_free(img); 
}