#include <thread>
#include <iostream>
using std::cout, std::endl;


int a;


void func()
{
    for (int i = 0; i < 1000000; ++i)
        a++;
}


int main()
{
    cout << a << endl;

    std::thread t1(func);
    std::thread t2(func);

    t1.join();
    t2.join();


    cout << a << endl;
}

/*
    Задача:

        0)  Будет ли равно значение переменной a числу 2000000, после того как потоки отработают?

        1)  Исправьте программу, используя объект std::mutex из библиотеки mutex.

        2)  Исправьте программу, используя std::lock_guard из библиотеки mutex.
*/
