#include <iostream>
#include <string>
using std::cout, std::endl;


void funcValue(std::string s)
{
    cout << s << endl;
}


void funcLvref(std::string& s)
{
    cout << s << endl;
}


void funcRvref(std::string&& s)
{
    cout << s << endl;
}


int main()
{
    std::string a {"Cat"};
    std::string b {"Dog"};

    // Передача в функцию, принимающую по значению

    funcValue(a);               // Копирование объекта a
    funcValue(a + b);           // Перемещение временного объекта a + b
    funcValue(std::move(a));    // Перемещение объекта a. Объект a в функции main станет пустой строкой.

    a = "Cat";



    // Передача в функцию, принимающую по lvalue-ссылки

    funcLvref(a);               // Передача объекта a по ссылке
    //funcLvref(a + b);         // Ошибка компиляции, rvalue нельзя передавать по lvalue-ссылке
    //funcLvref(std::move(a));  // Ошибка компиляции, rvalue нельзя передавать по lvalue-ссылке




    // Передача в функцию, принимающую по rvalue-ссылки

    //funcRvref(a);             // Ошибка компиляции, lvalue нельзя передавать по rvalue-ссылке
    funcRvref(a + b);           // Передача временного объекта по ссылке
    funcRvref(std::move(a));    // Передача объекта a по ссылке

}



/*
    Задача:

        Что будет происходить при передаче таких же аргументов в функцию, принимающую
        константную ссылку на lvalue?
*/