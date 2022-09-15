#include <iostream>
#include <string>
#include <string_view>
using std::cout, std::cin, std::endl;


std::string_view func()
{
    std::string a = "Cat and Dogs";
    return a;
}


int main()
{
    cout << func() << endl;
}


/*
    Решение:

        В программе ошибка - неопределённое поведение (UB). Независимо от размера строки.
        
        Строка std::string создаётся в функции func.
        Если строка большая, то данные этой строки будут храниться в Куче, если маленькая, то на стеке.

        В любом случае, когда мы выйдем из функции, строка a удалится.
        А объект string_view будет указывать на уже удалённые данные.

*/