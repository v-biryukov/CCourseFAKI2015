/*
    Алиасинг и оптимизация

    Алиасинг не позволяет компилятору сделать некоторые оптимизации, которые могли бы существенно ускорить программу.

    Например, в данной программе, компилятор мог бы заменить строку:

        return temp - *p;

    на строку:

        return 0;

    Но не может это сделать, так как в теории адрес q может быть равен адресу p и при изменении *q, изменится и *p.
*/

#include <stdio.h>


int func(int* p, int* q)
{
    int temp = *p;

    *q = 0;

    return temp - *p;
}



int main()
{
    int a = 10;
    int b = 20;

    printf("%i\n", func(&a, &b));
    printf("%i\n", func(&a, &a));
}