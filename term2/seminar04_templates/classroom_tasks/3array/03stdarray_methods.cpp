/*
    Методы std::array

    
    У класса std::array также есть удобные методы:

        size, empty, front, back, fill и другие.
*/

#include <iostream>
#include <array>
#include <string>
using std::cout, std::endl;


int main()
{
    std::array<int, 5> a {10, 20, 30, 40, 50};


    cout << a.size() << endl;
    cout << a.empty() << endl;
    cout << a.front() << endl;
    cout << a.back() << endl;


    a.fill(7);
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

