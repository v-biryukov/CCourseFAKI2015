/*
    Перемещение контейнера std::array

    Задача:

        У нас есть две объекта типа std::array<int, 5> и мы перемещаем один объект в другой.
        Что будут содержать контейнеры a и b после перемещения?
*/

#include <array>
#include <iostream>
#include <utility>
using std::cout, std::endl;

// Вспомогательная функция для печати массива std::array на экран
template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N>& a)
{
    for (auto el : a)
        out << el << " ";
    return out;
}


int main()
{
    std::array<int, 5> a {10, 20, 30, 40, 50};
    std::array<int, 5> b {60, 70, 80, 90, 100};

    cout << "array a = " << a << endl;
    cout << "array b = " << b << endl;

    b = std::move(a);
}

