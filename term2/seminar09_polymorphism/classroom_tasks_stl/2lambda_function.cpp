#include <iostream>
#include <vector>
#include <algorithm>

// Подключаем std::function
#include <functional>

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


// Элементы std::function сами являются объектами и их можно передавать в другие функции
// Например, вот функция, которая применяет функцию f к каждому элементу вектора:
void foreach(std::vector<int>& v, std::function<void(int&)> f)
{
    for (int& el : v)
    {
        f(el);
    }
}


int main()
{

    std::vector<int> v {5, 12, 7, 1, 8, 21, 5, 7};
    print_vector("Initial vector:", v);

    // Возводим в квадрат каждый элемент вектора
    foreach(v, [](int& a) {a = a * a;});
    print_vector("Squared vector:", v);

    // Отнимаем 10 от каждого элемента вектора
    foreach(v, [](int& a) {a -= 10;});
    print_vector("Minus 10 for every element:", v);


    // К счастью функция, аналогичная написанной нами foreach, уже написана в стандартной библиотеке:
    std::for_each(v.begin(), v.end(), [](int& a) {a *= 3;});
    print_vector("Tripling every element:", v);

    // Также есть множество других функций:
    
    // Подсчёт количества элементов:
    int number_of_odds = std::count_if(v.begin(), v.end(), [](int a) {return a % 2 == 1;});
    cout << "Number of odd numbers in vector = " << number_of_odds << endl;


    /* Задание:
        
        std::vector<std::string> animals { "Cat", "Dog", "Bison", "Dolphin", "Eagle", "Pony", "Ape", "Lobster", 
                                    "Monkey", "Cow", "Deer", "Duck", "Rabbit", "Spider", "Wolf", "Turkey", 
                                    "Lion", "Pig", "Snake", "Shark", "Bird", "Fish", "Chicken", "Horse"};
    
    1) Отсортируйте вектор animals

    2) Отсортируйте вектор animals по второй букве

    3) Обратите каждое слово в векторе animals
        Используйте функции std::for_each и std::reverse

    */


}