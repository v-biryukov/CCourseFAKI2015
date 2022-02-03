#include <vector>
#include <iostream>
using std::cout, std::endl;


/*

*/

std::vector<int> getNumbers()
{
    std::vector<int> v {10, 20, 30, 40, 50};
    cout << "Address of v: " << &v << ", address of v[0] " << &v[0] << endl;
    return v;
}



std::vector<int> getNumbers()
{
    std::vector<int> v {10, 20, 30, 40, 50};
    cout << "getNumbers:\t Address of v: " << &v << ", address of v[0] " << &v[0] << endl;
    return std::move(v);
}


int main()
{
    auto v = getNumbers();
    cout << "Address of v: " << &v << ", address of v[0] " << &v[0] << endl;
}