#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int main()
{
    std::vector<int> vec;
    cout << "Size = " << vec.size() << ";  Capacity = " << vec.capacity() << endl;

    // Добавьте в вектор элементы: 4 8 15 16 23 42
    // Ваш код:


    // Напечатайте их с помощью цикла, int i в качестве счётчик
    // Ваш код:


    // Напечатайте их с помощью цикла, используя итератор
    // Ваш код:


    // Напечатайте их с помощью range-based for цикла. При компиляции используёте опцию -std=c++11
    // Ваш код:


    // Отсортируйте вектор, используя функцию std::sort(<итератор на начало>, <итератор на конец>). 
    // Библиотека <algorithm>. Напечатайте этот вектор
    // Ваш код:


    // Отсортируйте вектор, по последней цифре 
    // Используйте функцию std::sort(<итератор на начало>, <итератор на конец>, cmp)
    // где cmp -- функция вида bool cmp(int a, int b). Напечатайте получившийся вектор
    // Ваш код:


    // Создайте новый вектор целых чисел и сразу инициализируйте его. Используёте -std=c++11.
    // Для инициализации используйте {}
    // Напечатай чему равны их значения size и capacity
    // Ваш код:


    // Добавьте в новый вектор 100 чисел. Проверяйте на каждой итерации чему равны size и capacity вектора
    for (int i = 0; i < 100; ++i)
    {
        // Ваш код:
        
    }


    // Что выведет следующая строка если в векторе vec будет 10 элементов и почему
    // cout << sizeof(vec) << endl;
}