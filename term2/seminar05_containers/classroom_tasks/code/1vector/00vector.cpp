/*
    Класс std::vector

    Шаблонный класс std::vector является самым важным классом-контейнером в C++
    Несмотря на название, этот класс не имеет никакого отношения к обычным векторам из математики.
    А представляет собой динамический (т.е. саморасширяющийся) массив.
    Он может хранить произвольное число элементов одинакового типа.

    Самые основные методы:

        1)  size_t size()               -   возвращает количество элементов в векторе
        2)  T& operator[](size_t i)     -   перегруженный оператор индексирования
                                            если выйти за границы, то будет неопределённое поведение
        3)  void push_back(const T& el) -   добавляет элемент в конец вектора

    В данной программе мы создаём вектор, состоящий из целых чисел и печатаем его на экран.

    
    Вектор уже рассматривался в предыдущем семинаре. 
    В этом семинаре мы рассмотрим методы вектора, связанные с итераторами.
*/

#include <iostream>
#include <vector>
#include <string>
using std::cout, std::endl;

int main()
{
    std::vector<int> v {10, 20, 30, 40, 50, 60, 70};

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;


    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}


/*
    Задача:

        Создайте вектор из строк типа std::string  "Cat", "Dog", "Mouse", "Lion" 
            
            std::vector<std::string> v {"Cat", "Dog", "Mouse", "Lion"};
        
        и напечатайте его. Для обхода вектора используйте итераторы.
*/