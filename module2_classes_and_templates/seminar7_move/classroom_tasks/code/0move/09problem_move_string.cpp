/*
    Перемещение строки std::string

    Задачи:

        1)  У нас есть две объекта типа std::string и мы перемещаем один объект в другой.
            Что будут содержать строки a и b после перемещения?

        2)  Для строки "Cat", какая операция более эффективна копирование или перемещение?
*/

#include <string>
#include <iostream>
#include <utility>
using std::cout, std::endl;

int main()
{
    std::string a = "Cat";
    std::string b = "Mouse";

    cout << "string a = " << a << endl;
    cout << "string b = " << b << endl;

    b = std::move(a);
}