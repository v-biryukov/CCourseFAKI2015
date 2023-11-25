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


void print1(const std::array<int, 5>& a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void print2(const std::array<double, 3>& a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void print3(const std::array<std::string, 4>& a)
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


    print1(a);
    print2(b);
    print3(c);
}

