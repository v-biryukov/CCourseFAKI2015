/*
    Как возвратить что-нибудь из вызванного потока в наш поток?


    Более правильный способ - это использование std::async и/или std::future/std::promice.
    Эти способы мы пройдём в следующих семестрах.


    Сейчас же можно попробовать передать в функцию ссылку на объект и таким образом "вернуть" что-то из функции.
    Это мы пытаемся сделать в этом примере.


    Но такой способ возврата из потока не будет работать.
    Дело в том, что внутри конструктора std::thread все аргументы копируются, а затем 
    перемещаются в функцию func. Поэтому такой способ приведёт к ошибке.
*/



#include <thread>
#include <iostream>
using std::cout, std::endl;


void func(int& x)
{
    x = 456;
}


int main()
{
    int a = 0;
    cout << a << endl;

    std::thread t(func, a);
    t.join();

    cout << a << endl;
}