/*
    Как возвратить что-нибудь из вызванного потока в наш поток?


    Если всё-же нужно создать поток от функции, которая принимает ссылку,
    то можно передать специальный объект std::reference_wrapper.
    Этот объект можно создать с помощью функции std::ref.
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

    std::thread t(func, std::ref(a));
    t.join();

    cout << a << endl;
}