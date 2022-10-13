#include <stdio.h>
#include <stdlib.h>
#define N 30

void quicksort(int array[], int l, int r) 
{
    if (r - l <= 1)
        return;

    int j = l;
    int pivot = array[r - 1];
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
    quicksort(array, l, j - 1);
    quicksort(array, j, r);
}

void print(int array[], int n) 
{
    for (int i = 0; i < n; i++) 
        printf("%d ", array[i]);

    printf("\n");
}

int main() 
{
    int numbers[N];
    for(int i = 0; i < N; i++) 
        numbers[i] = rand() % 100;

    
    print(numbers, N);
    quicksort(numbers, 0, N);
    print(numbers, N);
}