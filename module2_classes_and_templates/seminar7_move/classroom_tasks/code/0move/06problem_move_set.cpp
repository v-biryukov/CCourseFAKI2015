/*
    Перемещение контейнера std::set

    Задача:

        У нас есть две объекта типа std::set и мы перемещаем один объект в другой.
        Что будут содержать контейнеры a и b после перемещения?
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

    cout << "set a = " << a << endl;
    cout << "set b = " << b << endl;

    b = std::move(a);
}

