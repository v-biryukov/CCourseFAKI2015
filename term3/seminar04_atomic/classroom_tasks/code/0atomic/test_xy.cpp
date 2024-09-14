/*




*/

#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;
using std::cout, std::endl;

int x;
int y;


void f1()
{
    std::this_thread::sleep_for(50ms);
    
    x = 1000;

    cout << "y = " << y << endl;
}


void f2()
{
    std::this_thread::sleep_for(50ms);

    y = 1000;

    cout << "x = " << x << endl;
}



int main()
{

    for (int i = 0; i < 100000; ++i)
    {
        x = 0;
        y = 0;

        cout << "Start" << endl;
        std::thread t1(f1);
        std::thread t2(f2);

        t1.join();
        t2.join();
        cout << "Finish" << endl;
    }
}