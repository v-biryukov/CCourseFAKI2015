#include <iostream>
#include <thread>
using std::cout, std::cin, std::endl;

void task()
{
    cout << "Hello" << endl;
}

int main()
{
    std::thread a {task};

    a.join();

    cout << sizeof(a) << endl;
}