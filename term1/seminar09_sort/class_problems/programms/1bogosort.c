#include <stdio.h>
#include <stdlib.h>
 

void print_array(int array[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%4d ", array[i]);
    printf("\n");
}
 


int is_sorted(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
        if (array[i] > array[i + 1]) 
            return 0;
    return 1;
}
 
void shuffle(int array[], int n)
{
    for(int i = 0; i < n; i++) 
    {
        // Каждый элемент меняем местами со случайным
        int random_index = rand() % n;

        int temp = array[i];
        array[i] = array[random_index];
        array[random_index] = temp;
    }
}
 
void bogosort(int array[], int n)
{
    int iteration = 0;
    while (!is_sorted(array, n)) 
    {
        shuffle(array, n);
        printf("Iteration #%d:\t", iteration);
        print_array(array, n);
        iteration++;
    }   
}


int main()
{
    int n = 4;
    int numbers[] = {2, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
 
    // Сортируем первые n чисел массива
    bogosort(numbers, n);
    printf("Sorted:   ");
    print_array(numbers, n);
}