#include <iostream>
#include <array>
#include <fstream>

int main()
{
    const int width = 400;
    const int height = 300;
    std::array<unsigned char, 3> colorA {40, 80, 120};
    std::array<unsigned char, 3> colorB {80, 120, 40};

    std::ofstream out {"half.ppm"};
    out << "P3\n" << width << " " << height << "\n255\n";
    for (int j = 0; j < height; ++j)
    {
        for (int i = 0; i < width / 2; ++i)
            out << (int)colorA[0] << " " << (int)colorA[1] << " " <<(int)colorA[2] << "\n";

        for (int i = width / 2; i < width; ++i)
            out << (int)colorB[0] << " " << (int)colorB[1] << " " <<(int)colorB[2] << "\n";
    }
}