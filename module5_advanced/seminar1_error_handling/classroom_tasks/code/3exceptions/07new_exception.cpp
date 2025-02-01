#include <iostream>
#include <exception>
using std::cout, std::endl;


/*
    Оператор new кидает исключение std::bad_alloc
*/


void func()
{
    int* p = new int[10000000000];
    cout << p[10000000000 - 1] << endl;
}



int main()
{
    func();
}


/*
    Задания:
        1)  Поймайте это исключение
*/
