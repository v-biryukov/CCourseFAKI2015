/*
    Задача:
        
        Считайте массив из  n  элементов и напечатайте его в обратном порядке.
        Число поступающих на вход элементов не превосходит 1000.
        
        То есть, если на вход поступает

            5
            10 20 30 40 50

        То нужно напечатать

            50 40 30 20 10
*/


#include <stdio.h>

int main()
{
    int n;
    scanf("%i", &n);

    int a[1000];
    for (int i = 0; i < n; ++i)
        scanf("%i", &a[i]);
}