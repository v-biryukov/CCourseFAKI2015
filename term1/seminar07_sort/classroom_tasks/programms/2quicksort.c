#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionsort(int* array, int lo, int hi)
{
    for (int j = lo; j < hi; j++)
    {
        // Ищем индекс минимального элемента в подмассиве [j, hi]
        int min_index = j;
        for (int i = j + 1; i < hi; i++)
            if (array[i] < array[min_index])
                min_index = i;

        // Меняем минимальный и первый элементы в подмассиве [j, hi]
        int temp = array[min_index];
        array[min_index] = array[j];
        array[j] = temp;
    }


}

void quicksort(int* array, int lo, int hi)
{
    // Если hi - lo == 1, то в подмассиве 1 элемент, ничего делать не надо
    if (hi - lo > 1)
    {
        // Выбираем опорный элемент (в данном случае -- последний)
        int pivot = array[hi - 1];

        // Перемещаем элементы подмассива так, чтобы
        // в первой части стояли элементы <= pivot,
        // а во второй части элементы > pivot
        int j = lo;
        for (int i = lo; i < hi; i++)
            if (array[i] <= pivot)
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                j++;
            }

        // Сортируем эти 2 части рекурсивно
        quicksort(array, lo, j - 1);
        quicksort(array, j, hi);
    }
}

void print_array(int* array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Компиляция - gcc -std=c99 2quicksort.c
// Запуск     - ./a.out



int main()
{
    srand(time(0));
    int n = 20;
    int max = 1000;

    // Сгенерируем n чисел от 0 до max
    int* numbers = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        numbers[i] = rand() % max;
    
    print_array(numbers, n);
    quicksort(numbers, 0, n);
    print_array(numbers, n);
}