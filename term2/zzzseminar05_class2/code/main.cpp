#include "image.h"

int main()
{
    Image a;
    a.read("images/img5.ppm");
    a.reverse_colors();
    a.write("result.ppm");
}