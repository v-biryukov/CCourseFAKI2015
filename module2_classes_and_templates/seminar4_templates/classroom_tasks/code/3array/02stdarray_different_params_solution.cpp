/*
    Передача в функцию произвольного массива

    
    При передаче std::array в функцию нужно указать тип элементов и размер массива.
    Это логично, потому что типы, генерируемые от одного шаблона, на с разными шаблонными параметрами -
    это разные типы. Например типы:

        std::array<int, 5> 
        std::array<float, 5>
        std::array<int, 4>
        std::array<double, 3>

    это разные типы.

    Поэтому нужно написать разные функции для этих типов.

    Задача:

        Напишите шаблонную функцию, которая будет печатать массив std::array любого типа.
*/

#include <iostream>
#include <array>
#include <string>
using std::cout, std::endl;


template <typename T, std::size_t Size>
void print(const std::array<T, Size>& a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}


int main()
{
    std::array<int, 5> a {10, 20, 30, 40, 50};
    std::array<double, 3> b {2.1, 0.5, 7.4};
    std::array<std::string, 4> c {"Cat", "Dog", "Mouse", "Elephant"};


    print(a);
    print(b);
    print(c);
}

