#include <stdio.h>
#include <stdlib.h>
#define N 30

void selectionsort(int array[], int lo, int hi)
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

void quicksort(int array[], int lo, int hi)
{
    if (hi - lo > 1)
    {
        int j = lo;
        int pivot = array[hi - 1];
        for (int i = lo; i < hi; i++)
            if (array[i] <= pivot)
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                j++;
            }

        quicksort(array, lo, j - 1);
        quicksort(array, j, hi);
    }
}

void print(int array[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Компиляция - gcc -std=c99 0quicksort.c
// Запуск     - ./a.out

int main()
{
    int numbers[N];
    for(int i = 0; i < N; i++)
        numbers[i] = rand() % 100;
    
    print(numbers, N);
    quicksort(numbers, 0, N);
    print(numbers, N);
}