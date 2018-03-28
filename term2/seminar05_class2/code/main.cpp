#include "image.h"

int main()
{
    Image image;
    image.read("images/img5.ppm");
    image.reverse_colors();
    image.write("result.ppm");
}