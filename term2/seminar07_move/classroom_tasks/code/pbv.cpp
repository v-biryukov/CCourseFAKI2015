#include <iostream>
#include <vector>
using std::cout, std::endl;






void func(std::vector<int> v)
{
    cout << "Address of v: " << &v << ", address of v[0] " << &v[0] << endl;
}



int main()
{
    std::vector v {10, 20, 30, 40, 50};
    cout << "Address of v: " << &v << ", address of v[0] " << &v[0] << endl;

    func(v);
    func(std::move(v));
}