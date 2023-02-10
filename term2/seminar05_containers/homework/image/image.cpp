#include <iostream>
#include <functional>
#include <string_view>
#include <cmath>
#include <algorithm>
#include <fstream>
#include "image.h"

namespace mipt {


Image::Image()
{
}

Image::Image(const std::string& filename)
{
    read(filename);
}

Image::Image(int w, int h) : mWidth(w), mHeight(h)
{
    mData.resize(mWidth * mHeight * 3);
}

Image::Image(Vector2i sizes) :  mWidth(sizes.x), mHeight(sizes.y)
{
    mData.resize(mWidth * mHeight * 3);
}


int Image::getWidth() const
{
    return mWidth;
}

int Image::getHeight() const
{
    return mHeight;
}

int Image::getNumberOfPixels() const
{
    return mWidth * mHeight;
}

int Image::getNumberOfComponents() const
{
    return 3 * getNumberOfPixels();
}


// Считывания .ppm файла (файл должен быть без # комментариев)
void Image::read(const std::string& filename)
{
    std::ifstream in {filename, std::ios::binary};
    std::string tempP6;
    int temp255;
    in >> tempP6 >> mWidth >> mHeight >> temp255;

    mData.resize(mWidth * mHeight * 3);
    in.read(reinterpret_cast<char*>(&mData[0]), mData.size() * sizeof(ComponentType));
}

void Image::write(const std::string& filename) const
{
    std::ofstream out {filename, std::ios::binary};
    out << "P6\n" << mWidth << " " << mHeight << "\n255\n";
    out.write(reinterpret_cast<const char*>(&mData[0]), mData.size() * sizeof(ComponentType));
}

void Image::reverseColors()
{
     for (auto& component : mData)
     {
          component = 255 - component;
     }
}   


void Image::flipVertically()
{
    Color temp;
    for(int j = 0; j < mHeight / 2; j++)
    {
        for(int i = 0; i < mWidth; i++)
        {
            temp = getPixel({i, j});
            setPixel({i, j} , getPixel({i, mHeight - j - 1}));
            setPixel({i, mHeight - j - 1}, temp);
        }
    }
}

ComponentType& Image::at(int x, int y, int channel)
{
    return mData[3 * (x + y * mWidth) + channel];
}

void Image::clear(Color c)
{
    for (int j = 0; j < mHeight; j++)
        for (int i = 0; i < mWidth; i++)
            setPixel({i, j}, c);
}


void Image::drawCircle(int radius, Vector2i center, Color color)
{
    for (int j = std::max(center.y - radius, 0); j < std::min(center.y + radius, mHeight); j++)
    {
        for (int i = std::max(center.x - radius, 0); i < std::min(center.x + radius, mWidth); i++)
        {
            if ((i - center.x) * (i - center.x) + (j - center.y) * (j - center.y) < radius * radius)
                setPixel({i, j}, color);
        }
    }
}

void Image::drawLine(Vector2i p1, Vector2i p2, Color color)
{
    float x1 = p1.x;
    float y1 = p1.y;
    float x2 = p2.x;
    float y2 = p2.y;

    // Bresenham's line algorithm
    const bool steep = (std::abs(y2 - y1) > std::abs(x2 - x1));
    if(steep)
    {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }
 
    if(x1 > x2)
    {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
 
    const float dx = x2 - x1;
    const float dy = std::abs(y2 - y1);

    float error = dx / 2.0f;
    const int ystep = (y1 < y2) ? 1 : -1;
    int y = (int)y1;
 
    const int maxX = (int)x2;
 
    for(int x = (int)x1; x <= maxX; x++)
    {
        if(steep)
            setPixel({y, x}, color);
        else
            setPixel({x, y}, color);

        error -= dy;
        if(error < 0)
        {
            y += ystep;
            error += dx;
        }
    }
}

void Image::setPixel(Vector2i position, Color color)
{
    int id = position.x + position.y * mWidth;
    if (id < mWidth * mHeight)
    {
        mData[3 * id + 0] = color.r;
        mData[3 * id + 1] = color.g;
        mData[3 * id + 2] = color.b;
    }
}

Color Image::getPixel(Vector2i position) const
{
    int id = position.x + position.y * mWidth;
    Color c {mData[3 * id + 0], mData[3 * id + 1], mData[3 * id + 2]};
    return c;
}

}