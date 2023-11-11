/* 
    Константные ссылки можно создать, используя ключевое слово const

    int a = 10;
    const int& r = a;

    Это означает, что a нельзя будет изменить по этой ссылке
    То есть поменять a, используя ссылку r будет нельзя:
    r += 1; // Ошибка!
    a += 1; // OK

    
    Важным неочевидным отличием константных ссылок от обычных ссылок является то, что обычные ссылки
    можно инициализировать только объектами, которые уже храняться в памяти (например, переменными).

    int& r1 = a;    // OK
    int& r2 = 5;    // Ошибка

    Константные ссылки можно инициализировать чем угодно (нужно только чтобы тип совпадал)

    const int& cr1 = a; // OK
    const int& cr2 = 5; // OK
*/

#include <iostream>
#include <cmath>
using std::cout, std::endl;

int main() 
{
    int a = 10;
    const int& r = a;


    int& r1 = 20;       // Это не будет компилироваться
    const int& r2 = 20  // Тут всё ОК
}


/* 
    Задание:

    1)  Можно ли инициализировать ссылку таким образом?

            float& r = std::sqrt(2);

        Можно ли инициализировать константную ссылку таким образом?

            const float& r = std::sqrt(2);


    2)  Пусть есть функция:

            void printAgeV(int x)
            {
                cout << "My age is " << x << " years" << endl;
            }
    
        Можно ли вызвать её так?

            int a = 10;
            printAgeV(a)
        
        Можно ли вызвать её так?

            printAgeV(20)


    3)  Пусть есть функция:

            void printAgeR(int& x)
            {
                cout << "My age is " << x << " years" << endl;
            }
    
        Можно ли вызвать её так?
        
            int a = 10;
            printAgeR(a)
        
        Можно ли вызвать её так?
        
            printAgeR(20)


    4)  Пусть есть функция:

            void printAgeCR(const int& x)
            {
                cout << "My age is " << x << " years" << endl;
            }
    
        Можно ли вызвать её так?

            int a = 10;
            printAgeCR(a)
        
        Можно ли вызвать её так?

            printAgeCR(20)
*/