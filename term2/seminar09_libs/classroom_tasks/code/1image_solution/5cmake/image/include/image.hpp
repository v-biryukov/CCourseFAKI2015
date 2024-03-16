#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cassert>


class Image
{
private:
    int mWidth  {0};
    int mHeight {0};
    std::vector<unsigned char> mData {};

public:

    class Color
    {
    public:
        unsigned char r, g, b;
        Color& operator+=(Color c);
        Color operator+(Color c) const;

    private:
        unsigned char saturateCast(int a);
    };

    Image();
    Image(const std::string& filename);
    Image(int width, int height);
    Image(int width, int height, Color c);

    int getWidth() const {return mWidth;}
    int getHeight() const {return mHeight;}
    unsigned char* getData() {return mData.data();}

    void setPixel(int i, int j, Color c);
    Color getPixel(int i, int j) const;

    void loadPpm(const std::string& filename);
    void savePpm(const std::string& filename) const;

    void drawCircle(int radius, int centerX, int centerY, Color c);
    void drawLine(int x1, int y1, int x2, int y2, Color c);
};
