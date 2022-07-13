#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "type_name.hpp"
using std::cout, std::endl;


/*
    Ключевое слово decltype используется для того, чтобы вывести тип выражения

*/


int main()
{
    int a = 10;
    float b = 1.5;

    decltype(a + b) c = a + b;

    cout << typeName<decltype(c)>() << endl;
}   

/*
    1)  Что напечатает данная программа?

    2)  Пусть у нас есть две переменные
        long long int a = 10;
        char b = 20;
        
        Какой тип будет у их суммы?

    3)  Пусть у нас есть две переменные
        char a = 10;
        char b = 20;
        
        Какой тип будет у их суммы?


    4)  Пусть у нас есть две переменные
        long long int a = 10;
        float b = 20;
        
        Какой тип будет у их суммы?


    5)  Пусть есть переменная a некоторого типа
        Создайте ссылку на эту переменную, используя decltype

*/