#include <iostream>
#include <string>
using std::size_t;


template <typename T>
void selectionSort(T* array, size_t size) 
{
    for (size_t i = 0; i < size; ++i) 
    {
        size_t min_index = i;
        for (size_t j = i + 1; j < size; ++j)
            if (array[j] < array[min_index])
                min_index = j;


        T temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}

template <typename T>
void printArray(const T* array, size_t size) 
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

    
    double arrayd[5] = {1.5, 2.1, 6.9, 0.2, 4.7};
    selectionSort(arrayd, 5);
    printArray(arrayd, 5);


    std::string arraystr[5] = {"Mouse", "Cat", "Dog", "Axolotl", "Lion"};
    selectionSort(arraystr, 5);
    printArray(arraystr, 5);
}


/*
    Условия которые накладываются на тип объекта T в шаблонной функции selectionSort:

        1)  К объекту должен быть применим оператор <
            Если этот объект - класс, то у него должен быть метод operator<
            Используется тут:

                if (array[j] < array[min_index])


        2)  Объект можно инициализировать копированием
            Если этот объект - класс, то у него должен быть конструктор копирования
            Используется тут:

                T temp = array[i];


        3)  Объект можно присваивать
            Если этот объект - класс, то у него должен быть operator=
            Используется тут:

                array[i] = array[min_index];
                array[min_index] = temp;


    Условия которые накладываются на тип объекта T в шаблонной функции printArray:

        1)  Должен существовать перегруженный оператор вида operator<<(std::ostream&, T)
*/