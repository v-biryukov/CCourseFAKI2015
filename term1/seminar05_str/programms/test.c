#include <stdio.h>


int sum(int a, int b)
{
        int s = a + b;
        return s;
}
void print_sum(int a, int b)
{
        int p = sum(a, b);
        printf("Sum = %d\n", p);
}
int main()
{
        int x, y;
         scanf("%d%d", &x, &y);
         print_sum(x, y);      
        return 0;
}
