/*
    Задача:

        В данной программе один из потоков выводит на экран строки, состоящие из k символов 'A',
        а второй поток - строки, состоящие из k символов 'B'.

        Сами строки могут выводится в любом порядке, но они не должны перемешиваться друг с другом.
        В данной программе они перемешиваются. То есть первый поток может напечатать какое-то количество (меньше k)
        символов 'A', а потом второй поток может начать печатать символы 'B'.
        

        Сделайте так, чтобы строки не перемешивались.
        Используйте для этого класс std::mutex из библиотеки mutex.
*/




#include <thread>
#include <iostream>
#include <chrono>
using namespace std::chrono_literals;
using std::cout, std::endl;


const int n = 2000;
const int k = 50;

void func1()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            cout << 'A';
        }
        cout << '\n';
    }
}

void func2()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            cout << 'B';
        }
        cout << '\n';
    }
}


int main()
{
    std::thread t1(func1);
    std::thread t2(func2);

    t1.join();
    t2.join();
}