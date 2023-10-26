/*
    Но что если RVO оптимизация неприменима?

    Например, если мы возвращаем из функции один из его аргументов, то RVO неприменима.
    Нужно ли в этом случае писать std::move при возврате из функции?

    Ответ: нет, не нужно.
    Дело в том, что в этом случае объект будет перемещён автоматически, даже если вы не напишите std::move.
*/

#include <vector>
#include <iostream>
#include <utility>
using std::cout, std::endl;


std::vector<int> duplicate1(std::vector<int> v)
{
    cout << "Address of v: " << &v << ", address of v[0] " << &v[0] << endl;
    return v;
}


std::vector<int> duplicate2(std::vector<int> v)
{
    cout << "Address of v: " << &v << ", address of v[0] " << &v[0] << endl;
    return std::move(v);
}


int main()
{
    std::vector a {10, 20, 30, 40, 50};

    auto b = duplicate1(a);
    cout << "Address of b: " << &b << ", address of b[0] " << &b[0] << endl;
}


/*
    Запустите программу и убедитесь, что, когда не срабатывает RVO, объект перемещается автоматически.
*/