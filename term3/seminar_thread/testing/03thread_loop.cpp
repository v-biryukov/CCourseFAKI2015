#include <iostream>
#include <thread>
using std::cout, std::cin, std::endl;

void task()
{
    while (true)
    {
        cout << "Hello" << " ";
    }
}

int main()
{
    std::thread a {task};

    a.join();
}