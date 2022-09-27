#include <stdio.h>


int main()
{
    int a = 10;
    int b = 20;
    printf("Address of a: %p\n", &a);
    printf("Address of b: %p\n", &b);

    int* p = &a;

    printf("%p\n",  p);
    printf("%i\n", *p);

    // |||||||| Пишите код ниже ||||||||

    int** q = &p;

    *q = &b;

    printf("%p\n",  p);
    printf("%i\n", *p);
}