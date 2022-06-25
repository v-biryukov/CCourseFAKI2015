#include <stdio.h>

int main()
{
    int a[10] = {1, 12, 4, 3, 8, 17, 15, 6, 14, 5};

    for (int i = 9; i >= 0; --i)
    {
        printf("%i ", a[i]);
    }
    printf("\n");
}