#include "image.hpp"


int main()
{
    Image a(200, 100, {40, 80, 120});
    a.savePPMText("test.ppm");

    Image b{"house_binary.ppm"};

    for (int j = 0; j < b.getHeight(); ++j)
    {
        for (int i = 0; i < b.getWidth(); ++i)
            b(i, j) += Image::Color{50, 70, 90};
    }

    b.savePPMBinary("house_binary_result.ppm");
}
