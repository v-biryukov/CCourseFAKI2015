/*
    Польза перемещения

    Перемещение может быть полезно не только для временных объектов. 
    Перемещая обычные не временные объекты можно ускорить многие алгоритмы.

    Рассмотрим, например, задачу обмена значений двух строк.
    Без перемещения эту функцию можно написать так:

        void swap(std::string& a, std::string& b)
        {
            std::string temp = a;
            a = b;
            b = temp;
        }

    В этом случае внутри этой функции будет происходить три копирования строк.
    С перемещением эту функцию можно переписать следующим образом:

        void swap(std::string& a, std::string& b)
        {
            std::string temp = std::move(a);
            a = std::move(b);
            b = std::move(temp);
        }

    Теперь, за место трёх копирований будет происходить три перемещения, что обычно значительно эффективнее.
    С перемещением swap работает намного быстрее для объектов, выделяющих память в куче.
    Соответственно, будут работать намного быстрее все алгоритмы, использующие swap (например, алгоритмы сортировки).
*/

#include <iostream>
#include <utility>
#include <string>
using std::cout, std::endl;


void swap(std::string& a, std::string& b)
{
    std::string temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}


int main()
{
    std::string a {"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."};
    std::string b {"Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat."};


    cout << "a = " << a << endl;
    cout << "b = " << b << endl << endl;

    swap(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}


/*
    Задача:

        Напишите шаблонную функцию swap, которая бы обменивала бы два значения, используя перемещение, и работала
        бы не только для строк, но и для других типов.
*/