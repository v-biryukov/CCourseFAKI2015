/*
    Считывание двумерного массива

    Также как и в случае с одномерным массивом, мы пока не можем создать массив, чей размер мы не знаем заранее.

    Поэтому если мы хотим создать матрицу произвольного размера, мы используем тот же трюк, что и в случае с одномерным массивом.
    Мы создаём матрицу большого размера (например 100 на 100). Также мы считываем размеры матрицы n и m.
    И работаем только с частью большой матрицы размером n на m. Оставшиеся  100*100 - n*m  элементов мы даже не трогаем. 
    При этом мы конечно предполагаем, что размеры матрицы n и m не больше чем 100.

*/



#include <stdio.h>

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);


    int a[100][100];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            scanf("%i", &a[i][j]);
    }



    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            printf("%i ", a[i][j]);

        printf("\n");
    }
}


/*
    Задача:

        Напишите программу, которая будет сначала считывать с экрана 2 числа n и m.
        Потом эта программа должна считывать все элементы матрицы.
        Программа должна печатать на экран все элементы матрицы, умноженные на 2.

        При этом каждый раз вбивать матрицу руками необязательно.
        Матрицу можно считывать из файла вот так:

            ./a.out < matrix3.txt   (Linux)          a.exe < matrix3.txt   (Windows)
*/