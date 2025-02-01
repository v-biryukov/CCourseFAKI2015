








#include <iostream>
#include <thread>
using std::cout, std::endl;


void func()
{
    cout << std::this_thread::get_id() << endl;
}


int main()
{
    cout << std::this_thread::get_id() << endl;


    for (int i = 0; i < 10; ++i)
    {
        std::thread t{func};
        t.join();
    }
}