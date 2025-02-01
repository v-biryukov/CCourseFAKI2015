/*
    Как возвратить что-нибудь из вызванного потока в наш поток?


    Для возврата можно использовать глобальные или статические переменные.
*/



#include <thread>
#include <iostream>
using std::cout, std::endl;


int a;

void func()
{
    a = 456;
}


int main()
{
    cout << a << endl;

    std::thread t(func);
    t.join();

    cout << a << endl;
}