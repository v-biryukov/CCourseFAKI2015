#include <thread>
#include <iostream>
using std::cout, std::endl;



int main()
{
    std::thread t([](){cout << "Hello from thread" << endl;});

    cout << "Hello from main" << endl;

    t.join();
}


/*
    Объект std::thread можно инициализировать любым функциональным объектом.
*/