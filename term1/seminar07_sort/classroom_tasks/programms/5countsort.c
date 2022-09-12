#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int array[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);

    printf("\n");
}

void countsort(int array[], int n) 
{
    // Найдём максимальный элемент в массиве array
    // Создадим динамический массив counts размера равного максимальному числу
    // Занулим этот массив
    // Будем считать:
    // counts[i] = сколько раз в массиве array встречается число i

    // Исплользуя эту информацию, изменим массив array
}

int main() 
{
    srand(time(0));
    int n = 20;
    int max = 1000;

    int* numbers = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        numbers[i] = rand() % max;

    
    print_array(numbers, n);
    countsort(numbers, 0, n);
    print_array(numbers, n);
}