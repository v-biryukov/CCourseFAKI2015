/*
    Сравним размеры объектов std::list и std::forward_list.

    Реализация контейнеров не задаётся стандартом языка C++, соответственно она может различаться на разных системах/компиляторах.
    Следовательно, размеры объектов типов std::list и std::forward_list могут различаться на разных системах/компиляторах.

    Тем не менее типичный размер объекта типа std::list на 64-х битных системах это 24 байта, так как такой объект хранит
    указатель на первый узел, указатель на последний узел и количество элементов в списке.
    Количество элементов в списке std::list хранится в самом объекте, чтобы метод size() работал за O(1).

    Типичный размер объекта типа std::forward_list на 64-х битных системах это 8 байт, так как такой объект хранит только
    указатель на первый узел. В отличии от std::list, std::forward_list не хранит в своём объекте количество элементов.
    Следовательно, найти количество элементов объекта std::forward_list можно найти только за O(n).
    Это сделано для большей производительности других операций с односвязным списком.
*/

#include <iostream>
#include <list>
#include <forward_list>
#include <string>
using std::cout, std::endl;

int main()
{
    std::list<int> l {10, 20, 30, 40, 50};
    cout << "Size of list object = " << sizeof(l) << endl;

    std::forward_list<int> fl {10, 20, 30, 40, 50};
    cout << "Size of forward_list object = " << sizeof(fl) << endl;
}