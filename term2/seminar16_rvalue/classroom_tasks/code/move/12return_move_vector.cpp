#include <vector>
#include <iostream>
using std::cout, std::endl;


/*

*/



auto incNumbers(std::vector<int> v)
{
    for (auto& el : v)
        el++;
    cout << "incNumbers:\t Address of v: " << &v << ", address of v[0] " << &v[0] << endl;
    return v;
}



int main()
{
    std::vector a {10, 20, 30, 40, 50};
    cout << "Before inc:\t Address of a: " << &a << ", address of a[0] " << &a[0] << endl;

    auto b = incNumbers(std::move(a));
    cout << "After inc:\t Address of b: " << &b << ", address of b[0] " << &b[0] << endl;
}