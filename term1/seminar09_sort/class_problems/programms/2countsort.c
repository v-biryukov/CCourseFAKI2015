#include <stdio.h>
#include <stdlib.h>
#define N 5000

void print(int array[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void countsort(int array[], int n)
{
    // Заведём массив counts и будем считать 
    // counts[i] - сколько раз в массиве array встречается число i
}



int main()
{
    int numbers[N];
    for(int i = 0; i < N; i++)
        numbers[i] = rand() % 10;
    // Массив большой, но все числа массива очень маленькие (от 0 до 9)
    // Такой массив лучше всего сортировать подсчётом
    
    print(numbers, N);
}