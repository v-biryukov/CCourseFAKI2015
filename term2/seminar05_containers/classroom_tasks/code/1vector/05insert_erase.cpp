/*
    Методы insert и erase

    Метод insert принимает на вход итератор и некоторый элемент.
    Вставляет этот элемент до элемента, на который указывает итератор.

    Метод erase принимает на вход указатель и удаляет соответствующий элемент.

    Работают за O(k), где k это количесто элементов от места куда вставляем/удаляем и до конца вектора.
*/

#include <iostream>
#include <vector>
#include <string>
using std::cout, std::endl;

int main()
{
    std::vector<int> v {10, 20, 30, 40, 50, 60, 70};

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;



    std::vector<int>::iterator it = v.begin() + 3; // итератор указывает на элемент 40.
    v.insert(it, 100);

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;



    v.erase(v.end() - 2);

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;

}