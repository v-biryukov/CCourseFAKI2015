#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "type_name.hpp"
using std::cout, std::endl;


/*
    В примерах данного семинара часто будет необходимо напечатать тип выражения.
    В стандартной библиотеки C++ нет функции, которая возвращала полное название типа, но такую функцию можно написать.

    В файле type_name.hpp содержится шаблонная функция typeName, которая принимает тип через шаблонный аргумент
    и возвращает полное название типа в виде строки.


    В C++ есть множество различных типов, попробуем их классифицировать

    -) Встроенные типы
        int, float, unsigned int, bool, char и другие
        Встроенным также является тип nullptr_t


    -) Массивы, пришедшие из языка C
        При этом размер массива входит в описание типа, то есть
            int[5] и int[6] - это разные типы
        Существуют также многомерные массивы

    -) Объединения (union)

    -) Перечисления (enum)

    -) Структуры и классы (struct и class)

    -) Шаблонные структуры и классы

    -) Указатели
        Если есть некоторый тип T, то почти всегда существует тип T*
        В том числе если T - это указатель
        То есть, например, существует тип указатель на указатель ... на указатель на int


    -) Ссылки: lvalue и rvalue 
        Если есть некоторый тип T, то почти всегда существует тип T& или T&&
        Но типа ссылка на ссылку нет


    -) Квалификатор const
        Если есть некоторый тип T, то почти всегда существует тип const T

    
    -) Функции
        У функций есть тип, например, если есть функция
            int sum(int a, int b);

        То её тип будет int(int, int)

        К типу функции можно 'навесить' указатель или ссылку
        Указатель на функцию sum будет иметь тип   int(*)(int, int)
        Чтобы создать переменную такого типа нужно написать:
        int(*p)(int, int) = &sum;


    -) Лямбда-функции
        Не нужно путать лямбда-функции с обычными функциями
        Это тоже функциональные объекты, но у них другой тип


    -) Указатели на члены класса

*/


int sum(int a, int b) {return 12354;};

struct Book 
{
    std::string title;
    int pages;
    float price;

    int print(int x) {return 1;};
};


int main()
{
    cout << "Built-in types:" << endl;
    cout << typeName<int>() << endl;
    cout << typeName<float>() << endl;
    cout << typeName<unsigned char>() << endl;
    cout << typeName<bool>() << endl;
    cout << endl;


    cout << "C array types:" << endl;
    cout << typeName<int[10]>() << endl;
    cout << typeName<char[10][5]>() << endl;
    cout << endl;


    cout << "Struct:" << endl;
    cout << typeName<Book>() << endl;
    cout << endl;


    cout << "Templated classes:" << endl;
    cout << typeName<std::vector<int>>() << endl;
    cout << typeName<std::set<int, int>>() << endl;
    cout << endl;



    cout << "Pointer types:" << endl;
    cout << typeName<int*>() << endl;
    cout << typeName<char**>() << endl;
    cout << endl;


    cout << "References types:" << endl;
    cout << typeName<int&>() << endl;
    cout << typeName<Book&&>() << endl;
    cout << endl;


    cout << "Const types:" << endl;
    cout << typeName<const int>() << endl;
    cout << typeName<const Book&>() << endl;
    cout << typeName<const char&&>() << endl;
    cout << endl;


    cout << "Function types:" << endl;
    cout << typeName<void()>() << endl;
    cout << typeName<int(int)>() << endl;
    cout << typeName<Book(float, char)>() << endl;
    cout << typeName<int&&(const float&, char&)>() << endl;
    cout << endl;


    cout << "Function pointer/reference types:" << endl;
    cout << typeName<void(*)()>() << endl;
    cout << typeName<int(*)(int)>() << endl;
    cout << typeName<int(&)(int)>() << endl;
    cout << endl;


    cout << "C array pointer/reference types:" << endl;
    cout << typeName<int*[]>() << endl;
    cout << typeName<int(*)[10]>() << endl;
    cout << typeName<int(&)[]>() << endl;
    cout << endl;

}


/*
    Задачи:

    1)  Пусть есть массив:
        int a[5] = {10, 20, 30, 40, 50};

        Создайте:
        a)  Указатель на этот массив (на сам массив а не на элемент массива)
        б)  Ссылку на этот массив

        Поменяйте один из элементов массива, используя каждый из этих объектов


    2)  Есть функция sum

        Создайте:
        a)  Указатель на эту функцию
        б)  Ссылку на эту функцию

        Вызовите функцию, используя эти объекты




*/ 
