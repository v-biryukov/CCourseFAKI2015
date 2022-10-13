#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Сортирует подмассив [l, r] (то есть элементы с индексами от l до r - 1) методом выбора.
    Чтобы отсортировать весь массив вызовите эту функцию с l = 0 и r = size
*/

void selectionsort(int array[], int l, int r) 
{
    for (int j = l; j < r; j++) 
    {
        int min_index = j;
        for (int i = j + 1; i < r; i++)
            if (array[i] < array[min_index])
                min_index = i;


        int temp = array[min_index];
        array[min_index] = array[j];
        array[j] = temp;
    }
}


/*

    Сортирует подмассив [l, r] методом быстрой сортировки.

*/
void quicksort(int array[], int l, int r) 
{
    if (r - l <= 1) {
        return;
    }

    // Если в подмассиве более одного элемента:
    // Выбираем опорный элемент (в данном случае -- последний)
    int pivot = array[r - 1];

    // Перемещаем элементы подмассива так, чтобы
    // в первой части стояли элементы <= pivot,
    // а во второй части элементы > pivot
    int j = l;
    for (int i = l; i < r; i++) 
    {
        if (array[i] <= pivot) 
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            j++;
        }
    }

    // Сортируем эти 2 части рекурсивно
    quicksort(array, l, j - 1);
    quicksort(array, j, r);
}

void print_array(int array[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}


#define N 20

int main() 
{
    srand(time(0));
    
    int max = 1000;

    int numbers[N];
    for(int i = 0; i < N; i++)
        numbers[i] = rand() % max;
    
    print_array(numbers, N);
    quicksort(numbers, 0, N);
    print_array(numbers, N);
}