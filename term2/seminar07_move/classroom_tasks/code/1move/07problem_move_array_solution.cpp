/*
    Перемещение контейнера std::array

    Известно, что контейнеры std::array хранят все свои элементы в самом объекте и не выделяют память в куче
    и не используют никакого другого ресурса.
    
    Но если элементы std::array могут перемещаться, то было бы эффективно переместить их поэлементно.
    Поэтому, при перемещении контейнеров std::array, перемещаются все его элементы.
    В данном случае элементы это просто числа типа int, поэтому будет происходить обычное копирование.
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

    cout << endl;
    cout << "array a = " << a << endl;
    cout << "array b = " << b << endl;
}

