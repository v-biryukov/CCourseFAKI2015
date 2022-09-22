/*
    Но можно решить задачу лучше. Сделать так, чтобя для объектов типа std::string вызывалась своя версия функции.
    Этого можно добиться с помощью перегрузки функций.

    Когда компилятор увидет что нужно вызвать функцию triple от std::string он встанет перед выбором:

        
        1)  Вызвать уже готовую функцию std::string triple(std::string a)

        2)  Создать функцию самому из шаблона  T triple(T a)

    Если типы аргументов совпадают с типами у уже существующей функции, то компилятор не будет
    создавать свою функцию из шаблона, а просто вызовет уже готовую.
*/




#include <iostream>
#include <string>
using std::cout, std::endl;


template <typename T>
T triple(T a)
{
    return 3 * a;
}

std::string triple(std::string a)
{
    return a + a + a;
}


int main() 
{
    cout << triple(3) << endl;
    cout << triple(1.5) << endl;

    cout << triple(std::string("cat")) << endl;
}
