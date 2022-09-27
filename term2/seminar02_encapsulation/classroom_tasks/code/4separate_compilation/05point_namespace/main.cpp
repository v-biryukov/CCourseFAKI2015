/*
    Пространства имён


    Имя Point достаточно распространённое и есть очень большая вероятность того, что при подключении нескольких библиотек
    в некоторых из них тоже будет класс с именем Point. Конечно, если ничего не предпринять, это приведёт к ошибке.

    Чтобы избежать ошибок, связанных с конфликтами имён, положим весь код нашего класса Point в пространство имён mipt.
    Для этого обернём наш код в файлах point.hpp и point.cpp

        namespace mipt 
        {
            ...
        }

    Теперь наш класс Point будет лежать в пространстве имён mipt.
    Для его использования вне пространства имён mipt нужно писать mipt::Point (ну либо использовать using mipt::Point;)
*/


#include <iostream>
#include "point.hpp"

using std::cout, std::endl;

int main() 
{
    mipt::Point a = {7.2, 3.1};
    cout << a.norm() << endl;
}