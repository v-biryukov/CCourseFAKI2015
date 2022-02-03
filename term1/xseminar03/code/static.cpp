#include <stdio.h>

int f() 
{
    printf("f call!\n");
    return 1;
}

int g()
{
    static int a = f();
    printf("g call!\n");
}

int a = f();

int main() 
{
    printf("main call\n");
    g();
    g();
    g();
}