#include <stdio.h>

void inc(int* x)
{
    *x += 1;
}

int main()
{
    int x = 10;
    printf("%d\n", x);
    inc(10);
    printf("%d\n", x);

}
