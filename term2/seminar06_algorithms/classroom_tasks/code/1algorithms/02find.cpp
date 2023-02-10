/*
    Сортировка и обращение

    Библиотека algorithm

        std::find(it1, it2, el)  - ищет элемент, равный el на диапазоне [it1, it2)
                                   если таких элементов нет, то возвращает итератор .end()
                                   если таких элементов несколько, то возвращает итератор на первый их них

        std::count(it1, it2, el) - возвращает количество элементов, равных el на диапазоне [it1, it2)
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

}


/*
    Задачи:

        1)  На вход подаётся число. Напечатайте индекс этого элемента в массиве v.
            Если такого элемента нет, то напечатайте No such element
        
                вход                                выход

                96                                  5

                81                                  0
            
                50                                  No such element             
                       

        2)  Напишите функцию

                bool contains(const std::vector<int>& v, int el)

            которая будет проверять находится ли число el в векторе v
*/