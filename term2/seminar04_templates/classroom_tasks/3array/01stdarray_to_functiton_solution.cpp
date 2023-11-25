#include <iostream>
#include <array>
using std::cout, std::endl;


void printCArray(int a[], std::size_t n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void printStdArray(const std::array<int, 5>& a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void incCArray(int a[], std::size_t n)
{
    for (int i = 0; i < n; ++i)
    {
        a[i] += 1;
    }
}

void incStdArray(std::array<int, 5>& a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        a[i] += 1;
    }
}


int main()
{
    int a[5] = {10, 20, 30, 40, 50};
    incCArray(a, 5);
    printCArray(a, 5);


    std::array<int, 5> b = {10, 20, 30, 40, 50};
    incStdArray(b);
    printStdArray(b);
}
