#include <iostream>
#include <vector>
using std::cout, std::endl;


void func(std::vector<int> v)
{
    cout << &v << ", " << &v[0] << endl;
}




int main()
{
    std::vector v {10, 20, 30, 40};
    cout << "Initial:\t" << &v << ", " << &v[0] << endl;


    cout << "Pass by copy:\t";
    func(v);

    cout << "Pass by move:\t";
    func(std::move(v));
}

