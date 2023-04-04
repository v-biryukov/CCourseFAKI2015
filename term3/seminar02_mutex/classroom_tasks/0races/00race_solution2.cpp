#include <thread>
#include <iostream>
#include <mutex>
using std::cout, std::endl;


int a;
std::mutex m;

void func()
{
    for (int i = 0; i < 1000000; ++i)
    {
        std::lock_guard lk(m);
        a++;
    }
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