/*
    decltype

    Ключевое слово decltype используется для того, чтобы вывести тип выражения.
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
    int a = 10;
    float b = 1.5;

    decltype(a + b) c = a + b;

    cout << typeName<decltype(c)>() << endl;
}   

/*
    Задача 1:

        Пусть у нас есть две переменные:

            long long int a = 10;
            char b = 20;
        
        Какой тип будет у их суммы? Проверьте себя, используя функцию typeName.


    Задача 2:  

        Пусть у нас есть две переменные:
        
            char a = 10;
            char b = 20;
        
        Какой тип будет у их суммы? Проверьте себя, используя функцию typeName.


    Задача 3:   

        Пусть у нас есть две переменные:
    
            long long int a = 10;
            float b = 20;
        
        Какой тип будет у их суммы? Проверьте себя, используя функцию typeName.


    Задача 4:   

        Пусть есть переменная a некоторого типа.
        Сам тип нам неизвестен (например, потому что переменная создаётся с помощью auto).
        Создайте ссылку на эту переменную, используя decltype.
*/