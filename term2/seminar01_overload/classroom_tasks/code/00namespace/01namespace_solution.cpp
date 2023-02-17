#include <stdio.h>

namespace mipt 
{
    int a = 5;
    float b = 1.2;

    int square(int x)
    {
        return x * x;
    }

    float average(float x, float y)
    {
        return (x + y) / 2;
    }
}


int main() 
{
    printf("%i\n", mipt::square(mipt::a));
    printf("%f\n", mipt::average(mipt::a, mipt::b));
}
