/*
    Задача:

        Напишите шаблонную функцию void printInParentheses(const T& a), которая будет принимать на вход объект типа T,
        и печатать его в скобках. Известно, что объект типа T можно распечатать с помощью cout << a.
        

        printInParentheses(3);                  // напечатает   (3)
        printInParentheses(1.5)                 // напечатает   (1.500000) 
        printInParentheses(std::string("cat"))  // напечатает   (cat) 

        printInParentheses(Complex{4, 2})       // напечатает   (4 + 2i) 
        printInParentheses(Book{"Harry Potter", 500, 400.0});  // напечатает (Harry Potter, number of pages = 500, price = 500)

        
        В данной программе используются классы, написанные нами на прошлых занятиях:
            
            Complex - лежит в файле complex.h
            Book    - лежит в файле book.h

        Откройте эти файлы и посмотрите что делают эти классы.
*/




#include <iostream>
#include <string>

#include "book.h"
#include "complex.h"

using std::cout, std::endl;

int main() 
{
    cout << 3 << endl;


    Complex a {4, 2};
    cout << a << endl;

    Book b {"Harry Potter", 500, 400.0};
    cout << b << endl;
}
