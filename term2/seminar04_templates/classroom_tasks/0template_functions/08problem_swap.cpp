/*
    Задача:

        Напишите шаблонную функцию swap, которая будет принимать два объекта по ссылке
        обменивать их значения.
        Какие условия на пользовательский тип объекта будут накладываться в этой шаблонной функции?
*/

#include <iostream>
#include <string>
#include "book.h"
using std::cout, std::endl;




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
