#include <stdlib.h>  // malloc/free
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;

void add10(int& x)
{
    x += 10;
}

void add10_to_vector(std::vector<int> v)
{
    // Используем цикл с итератором
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        *it += 10;
}

void print_vector(const std::vector<int>& v)
{
    // Используем цикл с итератором
    for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}


int main()
{
    int a = 10;
    int& r = a;

    r += 10;
    // Что выведет на экран следующая строка?
    cout << a << endl;

    add10(a);
    // Что выведет на экран следующая строка?
    cout << r << endl;

    std::vector<int> v = {5, 3, 5, 10, 55, 5, 10, 55};
    print_vector(v);

    // Попытаемся прибавить 10 ко всем элементам вектора
    add10_to_vector(v);
    // Что выведет на экран следующая строка
    print_vector(v);

    // В коде есть ошибка! Исправьте её
}