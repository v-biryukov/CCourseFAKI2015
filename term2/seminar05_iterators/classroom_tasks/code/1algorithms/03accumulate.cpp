/*
    Суммирование

    Библиотека numeric

        std::accumulate(it1, it2, initialValue)
        вычисляет значение initialValue + *it1 + *(it1 + 1) + ... + *(it2 - 1)
        То есть суммирует все элементы на диапазоне [it1, it2) с элементом initialValue
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using std::cout, std::cin, std::endl;

int main()
{
    int n;
    cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

}

/*
    Задачи:

        1)  На вход подаётся n чисел. Напечатайте их сумму.
        
                вход                                выход

                8                                   39
                8 2 5 4 9 1 6 4       

                3                                   5000000000
                2000000000 1000000000 2000000000 
                       

        2)  На вход подаётся n чисел и ещё целое число k. 
            Напечатайте сумму k наименьших чисел. Известно, что k <= n.

                вход                                выход

                8                                   7
                8 2 5 4 9 1 6 4
                3
*/