#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// Печатаем n элементов массива A
void print_array(int array[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", array[i]);
    printf("\n");
}

// Сортировка выбором  (selection sort)
int selection_sort_array(int array[], int n)
{
    for(int i = 0; i < n; i++)
    {
        // Находим минимальный от i-го и до конца
        int jmin = i;
        for(int j = i + 1; j < n; j++)
            if(array[j] < array[jmin])
                jmin = j;

        // Меняем местами i-й и минимальный
        int temp = array[jmin];
        array[jmin] = array[i];
        array[i] = temp;
    }
}


// Функция, которая перемешивает массив
void shuffle(int array[], int n)
{
    if (n > 1) 
    {
        for (int i = 0; i < n - 1; i++) 
        {
          int j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}



int main()
{
    srand(time(NULL)); // Эта строка сбрасывает генератор случайных числе (нужно для перемешиавния массива)


    int A[20] = {-4, -42, -62, 47, 34, 39, 56, 81, -90, -56, 15, -12, -64, 78, 89, -35, 42, 41, 56, -79};

    printf("Начальный массив:\n");
    print_array(A, 20);

    printf("Сортируем:\n");
    selection_sort_array(A, 20);
    print_array(A, 20);

    printf("Перемешиваем:\n");
    shuffle(A, 20);
    print_array(A, 20);


    // Задание 1) Написать функцию сортировки пузырьком (Bubble sort)
    // Визуализацию сортировки пузырьком можно посмотреть в gif файле в этой папке
    

    // Задание 2) Написать функцию сортировки вставками (Insertion sort)
    // Визуализацию сортировки вставками можно посмотреть в gif файле в этой папке


    // Задание 3) Написать функцию принимает на вход массив, число его элементов и некоторое число k и проверяет
    // делятся ли все элементы массива на k.


    // Задание 4) Написать функции принимает на вход массив, число его элементов и
    // вычисляют среднее значение массива и дисперсию

}