#include "image.h"
#include <cstdlib>
#include <ctime>


void draw_random(Image& im)
{
	srand(time(0));
    for (int i = 0; i < im.get_width(); i++)
        for (int j = 0; j < im.get_height(); j++)
        {
            im.set_pixel({i, j}, {(unsigned char)rand(), (unsigned char)rand(), (unsigned char)rand()});
        }
}