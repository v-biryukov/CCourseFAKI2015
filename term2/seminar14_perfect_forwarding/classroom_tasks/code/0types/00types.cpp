/*
    Типы в языке C++

    В примерах данного семинара часто будет необходимо напечатать тип выражения.
    В стандартной библиотеки C++ нет функции, которая возвращала полное название типа, но такую функцию можно написать.

    В файле get_type_name.hpp содержится шаблонная функция getTypeName, которая принимает тип через шаблонный аргумент
    и возвращает полное название типа в виде строки типа std::string.


    В C++ есть множество различных типов, попробуем их классифицировать

    -) Встроенные типы

        int, float, unsigned int, bool, char и другие.
        Встроенным также является тип nullptr_t.


    -) Массивы, пришедшие из языка C

        При этом размер массива входит в описание типа, то есть int[5] и int[6] - это разные типы.
        Существуют также многомерные массивы.


    -) Объединения (union)

    -) Перечисления (enum)

    -) Структуры и классы (struct и class)

    -) Указатели

        Если есть некоторый тип T, то почти всегда существует тип T*.
        В том числе если T - это указатель.


    -) Ссылки: lvalue и rvalue 

        Если есть некоторый тип T, то почти всегда существует тип T& или T&&.
        Но типа ссылка на ссылку нет.


    -) Квалификатор const

        Если есть некоторый тип T, то почти всегда существует тип const T.

    
    -) Функции

        У функций есть тип, например, если есть функция

            int sum(int a, int b);

        То её тип будет int(int, int)

        К типу функции можно 'навесить' указатель или ссылку
        Указатель на функцию sum будет иметь тип   int(*)(int, int)
        Чтобы создать переменную такого типа нужно написать:
        int(*p)(int, int) = &sum;


    -) Функторы

        Функторы это просто классы, у которых определён operator().
    

    -) Лямбда-функции

        Не нужно путать лямбда-функции с обычными функциями.
        Лямбда-функции по сути являются функторами. Разница лишь в том, что есть синтаксические конструкции,
        которые позволяют создавать лямбда функции, без необходимости писать отдельный класс.


    -) Указатели на члены класса
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "get_type_name.hpp"
using std::cout, std::endl;



void sum(int a, int b) {cout << a + b << endl;};

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
    cout << getTypeName<int>() << endl;
    cout << getTypeName<float>() << endl;
    cout << getTypeName<unsigned char>() << endl;
    cout << getTypeName<bool>() << endl;
    cout << endl;


    cout << "C array types:" << endl;
    cout << getTypeName<int[10]>() << endl;
    cout << getTypeName<char[10][5]>() << endl;
    cout << endl;


    cout << "Struct:" << endl;
    cout << getTypeName<Book>() << endl;
    cout << endl;


    cout << "Templated classes:" << endl;
    cout << getTypeName<std::vector<int>>() << endl;
    cout << getTypeName<std::set<int, int>>() << endl;
    cout << endl;



    cout << "Pointer types:" << endl;
    cout << getTypeName<int*>() << endl;
    cout << getTypeName<char**>() << endl;
    cout << endl;


    cout << "References types:" << endl;
    cout << getTypeName<int&>() << endl;
    cout << getTypeName<Book&&>() << endl;
    cout << endl;


    cout << "Const types:" << endl;
    cout << getTypeName<const int>() << endl;
    cout << getTypeName<const Book&>() << endl;
    cout << getTypeName<const char&&>() << endl;
    cout << endl;


    cout << "Function types:" << endl;
    cout << getTypeName<void()>() << endl;
    cout << getTypeName<int(int)>() << endl;
    cout << getTypeName<Book(float, char)>() << endl;
    cout << getTypeName<int&&(const float&, char&)>() << endl;
    cout << endl;


    cout << "Function pointer/reference types:" << endl;
    cout << getTypeName<void(*)()>() << endl;
    cout << getTypeName<int(*)(int)>() << endl;
    cout << getTypeName<int(&)(int)>() << endl;
    cout << endl;


    cout << "C array pointer/reference types:" << endl;
    cout << getTypeName<int*[]>() << endl;
    cout << getTypeName<int(*)[10]>() << endl;
    cout << getTypeName<int(&)[]>() << endl;
    cout << endl;
}


/*
    Задача 1: 

        Пусть есть массив:
        
            int a[5] = {10, 20, 30, 40, 50};

        Создайте:

            a)  Указатель на этот массив (на сам массив а не на элемент массива)
            б)  Ссылку на этот массив (на сам массив а не на элемент массива)

        Поменяйте один из элементов массива, используя каждый из этих объектов


    Задача 2:   

        Есть функция sum:

            void sum(int a, int b) {cout << a + b << endl;};

        Создайте:

            a)  Указатель на эту функцию
            б)  Ссылку на эту функцию

        Вызовите функцию, используя эти объекты.
*/ 
