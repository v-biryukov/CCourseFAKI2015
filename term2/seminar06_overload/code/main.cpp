#include "image.h"

int main()
{
    Image image;
    image.read("img5.ppm");
    image.reverse_colors();
    image.write("img5_2.ppm");
}