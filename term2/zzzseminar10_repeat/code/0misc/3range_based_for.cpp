#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <typeinfo>

using std::cout;
using std::endl;

int main()
{
    // Начиная со стандарта C++11 есть ключевое слово auto:
    auto x = 42; // автоматически поймёт, что x это int

    std::vector<int> vec = {1, 5, 10, 7};
    std::vector<int>::iterator it1 = vec.begin(); // Обычное объявление итератора
    auto it2 = vec.begin();     // То же самое; автоматически поймёт, что it2 это std::vector<int>::iterator
    
    // Печатаем содержимое вектора с помощью итератора:
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
    cout << endl;
    // Упростите код выше с помощью auto


    // Начиная со стандарта C++11 можно использовать range-based for loop (гораздо более простой синтаксис)
    // Печатаем вектор:
    for (int el: vec)
        cout << el << " ";
    cout << endl;


    // Попробуем увеличить на 10 все элементы вектора:
    for (int el: vec)
        el += 10;

    for (int el: vec)
        cout << el << " ";
    cout << endl;

    // Исправьте код выше, так чтобы элементы вектора изменялись.
    // Используйте ссылку в качестве переменной цикла

}