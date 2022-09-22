#include <stdio.h>


int exchange(int* pvalue, int new_value)
{
    int result = *pvalue;
    *pvalue = new_value;
    return result;
}


int main()
{
    int a = 10;

    int b = exchange(&a, 20);

    printf("%i %i\n", a, b);
}