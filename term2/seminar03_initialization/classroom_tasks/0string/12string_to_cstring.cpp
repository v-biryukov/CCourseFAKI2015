/*
    Конветация строки типа std::string в строку языка C.

    Может понадобиться передать содержимое строки std::string в функцию, которая принимает по char* или по const char*.
    В этом случае можно использовать метод c_str класса std::string.
    Этот метод возвращает указатель const char* на сами данные в Куче и этот указатель можно передавать в функции языка C,
    если тип параметра const char*.

    Если же тип параметра char*, то передать туда указатель типа const char* не получится.
    Придётся создать новый массив элементов char, скопировать туда содержимое строки из строки std::string,
    а потом уже передать туда указатель на данные этого нового массива.
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using std::cout, std::cin, std::endl;


void funca(const char* str)
{
    printf("%s\n", str);
}

void funcb(char* str)
{
    printf("%s\n", str);
}


int main()
{
    std::string s = "Cat Dog Mouse";

    funca(s.c_str());

    char cs[20];
    std::strcpy(cs, s.c_str());
    funcb(cs);
}