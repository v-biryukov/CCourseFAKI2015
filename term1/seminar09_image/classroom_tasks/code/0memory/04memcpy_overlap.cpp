/*
    Функция memcpy

    

*/

#include <stdio.h>
#include <string.h>

#define SIZE ((size_t)10)

int main()
{
    unsigned char a[SIZE];

    for (size_t i = 0; i < SIZE; ++i)
    {
        a[i] =  i;
    }


    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%02hhx ", a[i]);
    }
    printf("\n");



    memcpy(a + 3, a, 6);



    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%02hhx ", a[i]);
    }
    printf("\n");






    for (size_t i = 0; i < SIZE; ++i)
    {
        a[i] =  i;
    }



    memmove(a + 3, a, 6);



    for (size_t i = 0; i < SIZE; ++i)
    {
        printf("%02hhx ", a[i]);
    }
    printf("\n");

}



/*
    Задача:

*/