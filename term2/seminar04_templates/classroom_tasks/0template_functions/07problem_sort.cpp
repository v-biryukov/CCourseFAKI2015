/*
    Задача:

        Мы написали алгоритм сортировки выбором массива из целых чисел типа int.
        Но мы не можем применить этот алгоритм сортировки, чтобы сортировать массив других объектов.

        Напишите шаблонную функцию, которая позволит сортировать объекты других типов.
        Какие условия на тип объекта будут накладываться в этой шаблонной функции?
        То есть какими методами (конструторами и/или перегруженными операторами) должен обладать класс объекта,
        чтобы массив таких объектов можно было использовать в шаблонной функции selectionSort.


        Также напишите шаблонную функцию printArray для печати массива объектов других типов.
        Какие условия на тип объекта будут накладываться шаблонной функции printArray?
*/

#include <iostream>
#include <string>
using std::size_t;


void selectionSort(int* array, size_t size) 
{
    for (size_t i = 0; i < size; ++i) 
    {
        size_t min_index = i;
        for (size_t j = i + 1; j < size; ++j)
            if (array[j] < array[min_index])
                min_index = j;


        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}


void printArray(const int* array, size_t size) 
{
    for (size_t i = 0; i < size; ++i)
        std::cout << array[i] << " ";
    printf("\n");
}



int main() 
{
    int arrayi[5] = {90, 20, 50, 10, 80};
    selectionSort(arrayi, 5);
    printArray(arrayi, 5);

    /*
    
    double arrayd[5] = {1.5, 2.1, 6.9, 0.2, 4.7};
    selectionSort(arrayd, 5);
    printArray(arrayd, 5);


    std::string arraystr[5] = {"Mouse", "Cat", "Dog", "Axolotl", "Lion"};
    selectionSort(arraystr, 5);
    printArray(arraystr, 5);
    
    */
}
