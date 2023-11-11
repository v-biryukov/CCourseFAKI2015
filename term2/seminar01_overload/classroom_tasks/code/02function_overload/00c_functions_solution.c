#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    printf("%i\n", abs(-5));
    printf("%lf\n", fabs(-5.9));

    double x = abs(-5.9);   // Используем не ту функцию!
    printf("%lf\n", x);
}