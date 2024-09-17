/*
    Пробелы после запятых

    Когда используются знаки препинания, например запятые, то нужно всегда ставить пробел после знака препинания
    и не ставить пробела до знака препинания.

        int a, b, c;
              ^  ^
              |  |
         запятая и пробел


        printf("%i %i\n", a, b);
                         ^  ^
                         |  |
                    запятая и пробел
*/



#include <stdio.h>

int main()
{
    int n;
    scanf("%i", &n);

    int fcurrent = 0, fnext = 1;
    int i = 0;

    while (i < n)
    {
        int temp = fnext;
        fnext = fnext + fcurrent;
        fcurrent = temp;

        i += 1;
    }

    printf("%i\n", fcurrent);
}
