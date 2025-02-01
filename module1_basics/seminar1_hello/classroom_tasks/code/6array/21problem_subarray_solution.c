#include <stdio.h>

int main()
{
    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int left, right;
    scanf("%i%i", &left, &right);

    for (int i = left; i < right; ++i)
        a[i] += 1;

    for (int i = 0; i < 10; ++i)
        printf("%i ", a[i]);
    printf("\n");
}


/*
    Чтобы программа увеличила все элементы массива нужно передать индексы   0 10

    Чтобы программа увеличила только элемент 50 нужно передать индексы   4 5

*/



