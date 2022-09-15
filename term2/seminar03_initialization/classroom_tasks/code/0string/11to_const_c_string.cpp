/*
    Получить C-строку из std::string

    Может понадобиться передать содержимое строки std::string в функцию, которая принимает по const char*.
    В этом случае можно использовать метод c_str класса std::string.
    Этот метод возвращает указатель const char* на сами данные в Куче и этот указатель можно передавать в функции языка C.

*/

#include <iostream>
#include <string>
#include <cstring>
using std::cout, std::cin, std::endl;


int main()
{
    std::string a = "Cat Dog Mouse";

    char b[20];
    strcpy(b, a.c_str());

    cout << b << endl;
}