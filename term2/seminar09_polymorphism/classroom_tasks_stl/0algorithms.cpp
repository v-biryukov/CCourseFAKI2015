#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

// Вспомагательная функция для печати вектора
void print_vector(std::string header, const std::vector<int>& vec)
{
    cout << header << endl << "\t";
    for (auto el : vec)
        cout << el << " ";
    cout << endl;
}


int main()
{
    std::vector<int> v {54, 12, 78, 1, 86, 92, 53, 87};

    print_vector("Initial vector:", v);

    // Обращение вектора
    std::reverse(v.begin(), v.end());
    print_vector("Reversed vector", v);

    // Сортировка вектора
    std::sort(v.begin(), v.end());
    print_vector("Sorted vector:", v);

    // Поиск элемента в векторе
    // Функция std::find возвращает соответствующий итератор (первого вхождения элемента)
    //                              или итератор end(), если такого элемента нет
    int a = 78;
    auto it = std::find(v.begin(), v.end(), a);
    if (it == v.end())
    {
        cout << "Element " << a <<  " not found!" << endl;
    }
    else
    {
        cout << "Element " << a << " found! Index = " << it - v.begin() << endl;
    }


    /* Задание:

    std::vector<std::string> animals { "Cat", "Dog", "Bison", "Dolphin", "Eagle", "Pony", "Ape", "Lobster", 
                                    "Monkey", "Cow", "Deer", "Duck", "Rabbit", "Spider", "Wolf", "Turkey", 
                                    "Lion", "Pig", "Snake", "Shark", "Bird", "Fish", "Chicken", "Horse"};
    
    1) Обратите вектор animals и напечатайте
    2) Отсортируйте вектор animals и напечатайте

    */
    
}