/*
    Задача:

        Напишите программу, которая будет создавать изображение half.ppm, размером 400 на 300
        пикселей, такое, что левая половина этого изображения будет иметь цвет colorA,
        а правая часть этого изображения будет иметь цвет colorB.
*/

#include <iostream>
#include <array>
#include <fstream>

int main()
{
    const int width = 400;
    const int height = 300;
    std::array<unsigned char, 3> colorA {40, 80, 120};
    std::array<unsigned char, 3> colorB {80, 120, 40};
}