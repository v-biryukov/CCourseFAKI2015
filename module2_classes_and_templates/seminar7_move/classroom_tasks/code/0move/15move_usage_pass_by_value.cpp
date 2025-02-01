/*
    Польза перемещения

    Перемещение ускоряет вашу программу даже если вы не используете std::move.
    Это происходит благодаря тому, что временные объекты перемещаются, там где это возможно.

    Пусть у нас есть 2 строки a и b и мы передаём в функцию, принимающую строку по значению, результат
    конкатенации этих строк:

        func(a + b);

    Что будет происходить в этом случае?

        1)  Сначала вычислится сумма a + b, то есть выполнится метод operator+ класса std::string.
            Этот метод вернёт результат конкатенации строк - временных объект типа std::string.

        2)  Так как этот объект временный, то в функцию он будет перемещаться, а не копироваться.
            Замена копирования перемещением ускоряет программу.


    !!  Если функцию принимает объект по значению, то временные объекты перемещаются в эту функцию автоматически
*/

#include <iostream>
#include <utility>
#include <string>
using std::cout, std::endl;


void func(std::string s)
{
    cout << s << endl;
}


int main()
{
    std::string a {"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "};
    std::string b {"Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat."};


    // Строка a копируется в функцию func
    func(a);


    // Сначала создаётся временная строка, результат сложения строк a и b
    // Потом эта строка перемещается в функцию func
    func(a + b);


    // С помощью функции std::move мы можем переместить и не временную строку
    // Только нужно помнить, что после этого строка a станет пустой
    func(std::move(a));


    cout << "After  func(std::move(a)), a = " << a << endl;
}