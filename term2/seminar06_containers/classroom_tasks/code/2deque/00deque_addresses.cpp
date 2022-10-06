#include <iostream>
#include <deque>
using std::cout, std::endl;

int main()
{
    std::deque d(1000, 5);

    int* prev = &d[0];

    for (auto& el : d)
    {
        cout << &el << " : " << (&el - prev) << endl;
        prev = &el;
    }

}