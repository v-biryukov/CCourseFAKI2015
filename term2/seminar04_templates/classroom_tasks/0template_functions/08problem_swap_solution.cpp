/*
    Условия на T, чтобы его можно было передать в функцию swap.
    Если T это пользовательский класс:

        1)  Конструктор копирования. Используется тут:

            T temp = a;

        2)  Перегруженный оператор присваивания. Используется тут:
    
            a = b;
            b = temp;
*/

#include <iostream>
#include <string>
#include "book.h"
using std::cout, std::endl;


template <typename T>
void swap(T& a, T&b)
{
    T temp = a;
    a = b;
    b = temp;
}


int main() 
{
    {
        int a = 10;
        int b = 20;

        cout << a << " " << b << endl; 
        swap(a, b);
        cout << a << " " << b << endl;
    }

    {
        float a = 1.5;
        float b = 4.7;

        cout << a << " " << b << endl; 
        swap(a, b);
        cout << a << " " << b << endl;
    }


    {
        std::string a {"Cat"};
        std::string b {"Dog"};

        cout << a << " " << b << endl; 
        swap(a, b);
        cout << a << " " << b << endl;
    }


    {
        Book a {"Harry Potter", 400, 500};
        Book b {"War and Peace", 1200, 900};

        cout << "Before swap:\n" << a << "\n" << b << endl; 
        swap(a, b);
        cout << "After swap:\n" << a << "\n" << b << endl;
    }

}
