/*
    Перемещение контейнера std::set

    Контейнеры std::set хранят свои элементы в куче, выделяя для них память.
    Как правило, std::set реализован как самобалансирующееся бинарное дерево поиска, память под каждый узел которого
    выделяется в куче. Поэтому, при перемещении контейнера std::set его элементы не копируются.

    Объект типа std::set, из которого производится перемещение, становится пустым.
*/

#include <set>
#include <iostream>
#include <utility>
using std::cout, std::endl;

// Вспомогательная функция для печати объекта типа std::set на экран
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& a)
{
    for (auto el : a)
        out << el << " ";
    return out;
}


int main()
{
    std::set<int> a = {10, 20, 30, 40, 50};
    std::set<int> b = {60, 70, 80, 90, 100};

    cout << sizeof(a) << endl;

    cout << "Before move" << endl;
    cout << "set a = " << a << endl;
    cout << "set b = " << b << endl;

    b = std::move(a);

    cout << endl << "After move:" << endl;
    cout << "set a = " << a << endl;
    cout << "set b = " << b << endl;
}

