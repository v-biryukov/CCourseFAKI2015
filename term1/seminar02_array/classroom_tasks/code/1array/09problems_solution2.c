#include <stdio.h>

int main()
{
    int a[10] = {1, 12, 4, 3, 8, 17, 15, 6, 14, 5};

    for (int i = 0; i < 10; ++i)
    {
        if (a[i] % 2 == 0)
        {
            printf("%i ", a[i]);
        }
    }
    printf("\n");
}