#include <iostream>
#include "image.hpp"


int main()
{
    Image a("asteroids.ppm");

    int n = std::min(a.getWidth(), a.getHeight());

    Image::Color blue{0, 0, 255};

    for (int i = 0; i < n; ++i)
    {
        a.setPixel(i, i, blue);      
    }

    a.savePPMBinary("result.ppm");
}