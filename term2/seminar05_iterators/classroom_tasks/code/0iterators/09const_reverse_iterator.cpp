/*
    Константные обратные итераторы
    
    Есть также константные обратные итераторы, тип const_reverse_iterator.
    Методы у контейнеров crbegin и crend.
*/



#include <iostream>
#include <vector>
#include <list>
using std::cout, std::endl;

int main()
{
    const std::vector<int> v {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    for (std::vector<int>::const_reverse_iterator it = v.crbegin(); it != v.crend(); ++it)
        cout << *it << " ";
    cout << endl;

}