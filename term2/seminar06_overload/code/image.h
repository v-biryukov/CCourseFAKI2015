#include <stdio.h>
#include <stdlib.h>

struct Pixel
{
     unsigned char red, green, blue;
};

class Image
{
private:
     int x, y;
     Pixel* data;
public:
    Image();
    Image(const char* filename);
    ~Image();


    void read(const char* filename);
    void write(const char* filename);
    
    void reverse_colors(); 
};