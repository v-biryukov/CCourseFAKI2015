#include <iostream>
#include <functional>
#include <cmath>
#include "image.h"

Image::Image()
{
    data = NULL;
}

Image::Image(const char* filename)
{
    data = NULL;
    read(filename);
}

Image::Image(int w, int h) : width(w), height(h)
{
    data = new Color[width * height];
}

Image::Image(const Vector2i& sizes) :  width(sizes.x), height(sizes.y)
{
    data = new Color[width * height];
}


Image::~Image()
{
    delete data;
}

int Image::get_width() const
{
    return width;
}

int Image::get_height() const
{
    return height;
}

// Считывания .ppm файла (файл должен быть без # комментариев)
void Image::read(const char* filename)
{
    FILE* inputfile = fopen(filename, "rb");
    if (inputfile == NULL)
    {
        std::cout << "Can't open the file: " << filename << std::endl;
        std::exit(1);
    }
    fscanf(inputfile, "P6\n%d %d\n255\n", &width, &height);
    data = (Color*)malloc(sizeof(Color) * width * height);
    fread(data, sizeof(Color), width * height, inputfile);
    fclose(inputfile);
}

void Image::write(const char* filename) const
{
    FILE* outputfile = fopen(filename, "wb");
    fprintf(outputfile, "P6\n%d %d\n255\n", width, height);
    fwrite(data, sizeof(Color), height * width, outputfile);
    fclose(outputfile);
}

void Image::reverse_colors()
{
    if(data)
    {
         for(int i = 0; i< width * height; i++)
         {
              data[i].r = 255 - data[i].r;
              data[i].g = 255 - data[i].g;
              data[i].b = 255 - data[i].b;
         }
    }
}   


void Image::flip_vertically()
{
    Color temp;
    if(data)
    {
        for(int j = 0; j < height / 2; j++)
        {
            for(int i = 0; i < width; i++)
            {
                temp = data[i + j * width];
                data[i + j*width] = data[i + (height - j - 1) * width];
                data[i + (height - j - 1) * width] = temp;
            }
        }
    }
}

Color& Image::at(int x, int y)
{
    return data[x + y*width];
}

void Image::clear(const Color& p)
{
    for (int j = 0; j < height; j++)
        for (int i = 0; i < width; i++)
            data[i + j*width] = p;
}


void Image::draw_circle(int radius, const Vector2i& center, const Color& color)
{
    std::function<int(int, int)> min = [](int a, int b) {return a > b ? b : a;};
    std::function<int(int, int)> max = [](int a, int b) {return a > b ? a : b;};
    for (int j = max(center.y - radius, 0); j < min(center.y + radius, height); j++)
    {
        for (int i = max(center.x - radius, 0); i < min(center.x + radius, width); i++)
        {
            if ((i - center.x) * (i - center.x) + (j - center.y) * (j - center.y) < radius * radius)
                data[i + j*width] = color;
        }
    }
}

void Image::draw_line(float x1, float y1, float x2, float y2, const Color& color)
{
    // Bresenham's line algorithm
    const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
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
    const float dy = fabs(y2 - y1);

    float error = dx / 2.0f;
    const int ystep = (y1 < y2) ? 1 : -1;
    int y = (int)y1;
 
    const int max_x = (int)x2;
 
    for(int x = (int)x1; x <= max_x; x++)
    {
        if(steep)
            set_pixel({y, x}, color);
        else
            set_pixel({x, y}, color);

        error -= dy;
        if(error < 0)
        {
            y += ystep;
            error += dx;
        }
    }
}

void Image::draw_line(const Vector2i& p1, const Vector2i& p2, const Color& color)
{
    draw_line(p1.x, p1.y, p2.x, p2.y, color);
}


void Image::set_pixel(const Vector2i& position, const Color& color)
{
    int id = position.x + position.y*width;
    if (id >= 0 && id < width * height)
        data[position.x + position.y*width] = color;
}

Color Image::get_pixel(const Vector2i& position) const
{
    return data[position.x + position.y*width];
}

