#include <stdio.h>
#include <stdlib.h>

namespace mipt 
{
    int a = 5;
    int b = 9;

    int square(int x)
    {
        return x * x;
    }

    int distance(int x, int y)
    {
        return abs(a - y);
    }
}


int main() 
{
    printf("%i\n", mipt::square(mipt::a));
    printf("%i\n", mipt::distance(mipt::a, mipt::b));
}
