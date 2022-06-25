#include <stdio.h>

int main()
{
    int a[10] = {1, 12, 4, 3, 8, 17, 15, 6, 14, 5};

    int sum = 0;
    for (int i = 0; i < 10; ++i)
    {
        sum += a[i];
    }

    printf("%i\n", sum);
}