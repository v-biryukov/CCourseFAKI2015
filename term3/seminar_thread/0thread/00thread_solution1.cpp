#include <thread>
#include <iostream>
using std::cout, std::endl;


void func()
{
    cout << "Hello from thread" << endl;
}


int main()
{
    std::thread ta(func);
    std::thread tb(func);
    std::thread tc(func);

    cout << "Hello from main" << endl;

    ta.join();
    tb.join();
    tc.join();
}