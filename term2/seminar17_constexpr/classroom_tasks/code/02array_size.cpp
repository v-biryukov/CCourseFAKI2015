#include <iostream>
#include <array>
using std::cout, std::cin, std::endl;


int getSize()
{
    return 5;
}

int main()
{
    const int n = getSize();
    std::array<int, n> a;

    for (auto el : a)
        cout << el << " ";
    cout << endl;
}