/*
    Сортировка с компаратором

    На вход функции std::sort можно передать функциональный объект.
    Например, можно передать функцию.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout, std::endl;

template <typename T>
void printVector(const std::vector<T>& v)
{
    for (typename std::vector<T>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
        cout << *it << " ";
    cout << endl;
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    std::vector<int> v {81, 82, 78, 36, 39, 96, 11, 58, 15, 48};

    printVector(v);
    std::sort(v.begin(), v.end(), cmp);
    printVector(v);
}


/*
    Задачи:

        1)  Отсортируйте вектор v по возрастанию последней цифры и напечатайте его.
            Если последняя цифра совпадает, то можно печатать в любом порядке.
            Должно получиться:
            
                81 11 82 15 36 96 78 58 48 39
*/