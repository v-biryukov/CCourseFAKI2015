/*
    Методы begin() и end()

    begin() возвращает итератор на первый элемент.

    end()   возвращает итератор на фиктивный элемент следующий после последнего.
            итератор end() нельзя разыменовывать, это приведёт к неопределённому поведению.
            С ним можно сравнивать другие итераторы, а также отнимать целые числа.
            Например, если вектор v не пуст, то  *(v.end() - 1)  это последний элемент. 
*/

#include <iostream>
#include <vector>
#include <string>
using std::cout, std::endl;

int main()
{
    std::vector<int> v {10, 20, 30, 40, 50, 60, 70};

    cout << *v.begin() << endl;
    cout << *(v.end() - 1) << endl;

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}