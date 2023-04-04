#include <iostream>
#include <thread>
using std::cout, std::endl;


int main()
{
    unsigned int n = std::thread::hardware_concurrency();
    cout << n << endl;
}

