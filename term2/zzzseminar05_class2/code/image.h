#include <stdio.h>
#include <stdlib.h>

struct Pixel
{
     unsigned char r, g, b;
     Pixel(){};
     Pixel(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {};
};

class Image
{
private:
     int size_x, size_y;
     Pixel* data;
public:
    Image();
    Image(const char* filename);
    ~Image();


    void read(const char* filename);
    void write(const char* filename);
    
    void reverse_colors(); 
    void flip_vertically(); 
};
