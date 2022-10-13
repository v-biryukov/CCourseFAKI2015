#include <stdio.h>

void print(int a) 
{ 
    printf("%d\n", a); 
} 

void sayntimes(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Hello ");
    }
    printf("\n");
}

void square(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < n; i++)
            printf("*");
        printf("\n");
    }
}

/*
    Создадим указатель на функцию и зададим его равным адресу print
    
        void (*p)(int n) = print;



    В дальнейшем p можно пользоваться как будто это функция print
*/

int main()
{

    void (*p)(int n) = print;
    p(4);

    p = sayntimes;
    p(4);

    p = square;
    p(4);


    void (*array[3])(int n) = {print, sayntimes, square};
    
    for (int i = 0; i < 3; i++)
        array[i](10);
}