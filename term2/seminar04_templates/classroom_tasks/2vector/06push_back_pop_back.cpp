/*
    Методы push_back и pop_back

    Метод push_back используется для добавления элемента в конец вектора.
    Метод pop_back  удаляет элемент из конца вектора.

    Оба метода работают за O(1) в среднем.
*/

#include <iostream>
#include <vector>
#include <string>
using std::cout, std::endl;

int main()
{
    std::vector<int> v {10, 20, 30, 40, 50};

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;



    cout << "Deleting last element" << endl;
    v.pop_back();

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;


    cout << "Adding element in the end" << endl;
    v.push_back(70);

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}