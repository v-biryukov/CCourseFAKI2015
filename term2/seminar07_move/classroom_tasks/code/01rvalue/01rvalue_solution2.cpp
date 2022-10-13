#include <iostream>
#include <vector>
using std::cout, std::endl;


void printCategory(int& a)
{
    cout << "lvalue" << endl;
}

void printCategory(int&& a)
{
    cout << "rvalue" << endl;
}

int main()
{
    int a = 10;
    printCategory(a);
    printCategory(20);
    printCategory(a + 1);

    std::vector<int> b {10, 20, 30, 40, 50};
    printCategory(b[0]);
}