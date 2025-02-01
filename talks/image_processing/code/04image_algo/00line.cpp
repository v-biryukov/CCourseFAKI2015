/*
    Алгоритм Брезенхема

    drawLine работает только при улах линии с осью Ox от -45 до +45 градусов

*/


#include <iostream>
#include "image.hpp"
#include <cmath>

void drawLine(Image& im, int x0, int y0, int x1, int y1)
{
    int dx = std::abs(x1 - x0);
    int dy = std::abs(y1 - y0);
    int error = 0;

    int diry = y1 - y0;
    if (diry > 0) diry = 1;
    if (diry < 0) diry = -1;

    int y = y0;
    for (int x = x0; x < x1; ++x)
    {
        im.setPixel(x, y, Image::Color{0, 0, 0});
        error = error + dy;
        if (error >= dx)
        {
            y = y + diry;
            error = error - dx;
        }
    }
}


int main()
{
    Image a(800, 800, {255, 255, 255});


    drawLine(a, 0, 400, 400, 100);
    drawLine(a, 0, 400, 400, 200);
    drawLine(a, 0, 400, 400, 300);
    drawLine(a, 0, 400, 400, 400);
    drawLine(a, 0, 400, 400, 500);
    drawLine(a, 0, 400, 400, 600);
    drawLine(a, 0, 400, 400, 700);

    a.savePPMBinary("result.ppm");
}
