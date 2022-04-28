#include <iostream>
#include <cmath>
using std::cout, std::endl;

/* 



*/




int main() 
{
    int a = 10;
    const int& r = a;

    cout << r << endl;
    a += 1;
    cout << r << endl;

}


/* 
    Задание:

    1)  Можно ли инициализировать ссылку таким образом?
        float& r = std::sqrt(2);

        Можно ли инициализировать константную ссылку таким образом?
        float& r = std::sqrt(2);


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