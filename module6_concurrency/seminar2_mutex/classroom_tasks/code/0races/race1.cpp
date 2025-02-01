/*




*/

#include <iostream>
#include <atomic>
#include <thread>
using std::cout, std::endl;

int a = 0;
int b = 0;

const int n = 10000;

void f1()
{
    for (int i = 0; i < n; ++i)
    {
        a++;
        cout << a << ", " << b << endl;
    }
}


void f2()
{
    for (int i = 0; i < n; ++i)
    {
        b++;
        cout << a << ", " << b << endl;
    }
}


int main()
{
    std::thread t1(f1);
    std::thread t2(f2);


    t1.join();
    t2.join();
}