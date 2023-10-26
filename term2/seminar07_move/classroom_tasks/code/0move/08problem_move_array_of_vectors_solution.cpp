/*
    Перемещение контейнера std::array

    Перемещение контейнеров std::array работает таким образом, что происходит поэлементное перемещение.
    В данном случае элементы массива это объекты типа std::vector, поэтому каждый из этих векторов одного массива
    будет перемещаться в соответствующий элемент другого массива.
*/

#include <array>
#include <vector>
#include <iostream>
#include <utility>
using std::cout, std::endl;

// Вспомогательная функция для печати массива std::array на экран
template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N>& a)
{
    out << '[';
    for (auto el : a)
        out << el << " ";
    out << ']';
    return out;
}

// Вспомогательная функция для печати std::vector на экран
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v)
{

    out << '{';
    for (auto el : v)
        out << el << " ";
    out << '}';
    return out;
}


int main()
{
    std::array<std::vector<int>, 3> a {std::vector<int>{10, 20, 30}, std::vector<int>{40, 50, 60}, std::vector<int>{70, 80, 90}};
    std::array<std::vector<int>, 3> b {std::vector<int>{15, 25, 35}, std::vector<int>{45, 55, 65}, std::vector<int>{75, 85, 95}};

    cout << "array a = " << a << endl;
    cout << "array b = " << b << endl;

    b = std::move(a);

    cout << "array a = " << a << endl;
    cout << "array b = " << b << endl;
}

