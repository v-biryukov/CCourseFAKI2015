/*
    Сортировка с компаратором - лямюда функцией

    Специально создавать функцию, чтобы передать её один раз на вход алгоритму, можно, но 
    это приведёт к тому, что весь код будет наводнён функциями, которые используются по одному разу.

    Для этой цели можно использовать другие функциональный объекты, а именно так называемые лямбда-функции.
    Чтобы создать лямбда функцию нужно написать:

        [](аргументы){тело функции}

    Более подробно лямбда функции мы пройдём позже.
    Одно из преемуществ лямбда-функций заключается в том, что их можно передавать как аргументы в функции.
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

int main()
{
    std::vector<int> v {81, 82, 78, 36, 39, 96, 11, 58, 15, 48};

    printVector(v);
    std::sort(v.begin(), v.end(), [](int a, int b) {return a > b;});
    printVector(v);
}


/*
    Задачи:

        1)  Отсортируйте вектор v по возрастанию последней цифры и напечатайте его.
            Если последняя цифра совпадает, то можно печатать в любом порядке.
            Должно получиться:
            
                81 11 82 15 36 96 78 58 48 39
*/