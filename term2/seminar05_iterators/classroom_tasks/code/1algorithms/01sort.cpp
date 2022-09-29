/*
    Сортировка и обращение

    Библиотека algorithm

        std::sort(it1, it2)     - сортирует диапазон [it1, it2)

        std::reverse(it1, it2)  - обращает диапазон

        std::partial_sort(it1, it, it2); - частично сортирует диапазон [it1, it2)
                                           наименьшие (it - it1) элементов будут отсортированы
*/

#include <iostream>
#include <vector>
#include <algorithm>
using std::cout, std::endl;

template <typename T>
void printVector(const std::vector<T>& v)
{
    for (typename std::vector<T>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}


int main()
{
    std::vector<int> v {81, 82, 78, 36, 39, 96, 11, 58, 15, 48};

    printVector(v);
    std::reverse(v.begin(), v.end());
    printVector(v);
}


/*
    Задачи:

        1)  На вход подаётся n чисел. Отсортируйте их по возрастанию и напечатайте
        
                вход                                выход

                10                                  
                81 82 78 36 39 96 11 58 15 48       11 15 36 39 48 58 78 81 82 96


        
        2)  На вход подаётся n строк. Отсортируйте их по возрастанию и напечатайте
        
                вход                                выход

                5                                   Cat Cheetah Lion Lynx Tiger
                Lion Tiger Cat Cheetah Lynx


        3)  На вход подаётся n строк. Обратите каждую строку. Затем отсортируйте их по возрастанию и напечатайте.
        
                вход                                выход

                5                                   
                Lion Tiger Cat Cheetah Lynx         hateehC noiL regiT taC xnyL
*/