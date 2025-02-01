/*
    Метод operator=

    Вектора можно присваивать друг другу.
*/

#include <iostream>
#include <vector>
#include <string>
using std::cout, std::endl;

int main()
{
    std::vector<int> v {10, 20, 30, 40, 50};
    std::vector<int> u {1, 2, 3};


    for (int i = 0; i < u.size(); ++i)
        cout << u[i] << " ";
    cout << endl;


    u = v;


    for (int i = 0; i < u.size(); ++i)
        cout << u[i] << " ";
    cout << endl;
}