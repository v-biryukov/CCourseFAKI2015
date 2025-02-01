/*
    На самом деле decltype работает по разному в зависимости от выражения

    1)  Если на вход приходит просто имя объекта или имя поля класса/структуры
        То decltype точно выводит тип.

    2)  Если на вход приходит lvalue-выражение, не являющееся одним именем
        То decltype добавляет ссылку к типу.
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "type_name.hpp"
using std::cout, std::endl;


int main()
{
    int a = 100;
    int b[5] = {10, 20, 30, 40, 50};

    cout << "decltypes of a and b:" << endl;
    cout << typeName<decltype(a)>() << endl;
    cout << typeName<decltype(b)>() << endl;

    cout << endl << "decltypes of expressions:" << endl;
    cout << typeName<decltype(1)>() << endl;
    cout << typeName<decltype(a + 1)>() << endl;
    cout << typeName<decltype(++a)>() << endl;
    cout << typeName<decltype(a++)>() << endl;
    cout << typeName<decltype((a))>() << endl;

    cout << endl << "decltypes of pointer dereference:" << endl;
    int* p = &a;
    cout << typeName<decltype(*p)>() << endl;


    cout << endl << "decltype of an array element:" << endl;
    cout << typeName<decltype(b[1])>() << endl;

}


/*
    Задача:

    Пусть есть структура:

        struct Book
        {
            char title[100];
            int pages;
            float price;
        };

        Book x;


    Как выведет тип decltype в следующих выражениях:

        x
        x.pages
        x.title
        x.title[1]

    Проверьте себя, использовав функцию typeName.
*/
