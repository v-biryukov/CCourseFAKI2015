#include <stdio.h>

void print_address(int* p)
{
    printf("%p\n", p);
}


int main()
{
    int a = 10;
    int* p = &a;

    int b = 20;

    print_address(&a);  // Адрес а
    print_address(p);   // Адрес a

    print_address(&b);  // Адрес b
}