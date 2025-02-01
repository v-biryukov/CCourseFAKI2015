#include <iostream>
#include <vector>
#include <string>
using std::cout, std::endl;

int main()
{
    std::vector<int> v {10, 20, 30, 40, 50, 60, 70};

    cout << *(v.rbegin() + 2) << endl;
    cout << v.rbegin()[2] << endl;
}