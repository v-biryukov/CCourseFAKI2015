#include <stdio.h>
#include <stdlib.h>


void print_array(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}



int main() {
    // Отсортируйте эти 100 чисел методом подсчёта
    int array[100] = {0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 
        1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 
        1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1};

    printf("Before Sorting:\n");
    print_array(array, 100);

    // Тут ваша сортировка (нужно подсчитать)

    printf("After Sorting:\n");
    print_array(array, 100);
}