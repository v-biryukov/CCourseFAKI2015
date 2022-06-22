#include <stdio.h>

int main()
{
    int n;
    scanf("%i", &n);

    int i = 1;
    while (i <= n)
    {
        printf("%i ", i * i % 10);
        ++i;
    }

    printf("\n");
}


/*
    Последнее число печатаем отдельно, чтобы не напечатать лишний плюс в конце
*/