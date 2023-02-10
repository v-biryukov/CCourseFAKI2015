/*
    Рассмотрим операцию перемещения вектора

    Функции std::move можно использовать и при присваивании.
    В данном примере, у нас есть два вектора и мы перемещаем вектор b в вектор a при присваивании.
    Происходит так называемое присваивание перемещения.
*/

#include <vector>
#include <iostream>
#include <utility>
using std::cout, std::endl;

// Вспомагательная функция для вывода вектора на экран
std::ostream& operator<<(std::ostream& out, const std::vector<int>& v)
{
    for (auto el : v)
        out << el << " ";
    return out;
}

int main()
{
    std::vector<int> a {10, 20, 30, 40, 50};
    std::vector<int> b {50, 60, 70, 80, 90};


    cout << "Before move: " << endl;
    cout << "vector a = " << a << endl;
    cout << "vector b = " << b << endl;
    cout << "vector a: size = " << a.size() << ", capacity = " << a.capacity() << ", pointer = " << &a[0] << endl;
    cout << "vector b: size = " << b.size() << ", capacity = " << b.capacity() << ", pointer = " << &b[0] << endl;


    b = std::move(a);


    cout << endl << "After move: " << endl;
    cout << "vector a = " << a << endl;
    cout << "vector b = " << b << endl;
    cout << "vector a: size = " << a.size() << ", capacity = " << a.capacity() << ", pointer = " << &a[0] << endl;
    cout << "vector b: size = " << b.size() << ", capacity = " << b.capacity() << ", pointer = " << &b[0] << endl;

}



/*
    Задание:

        1)  Создайте новый вектор c и иницилизируйте его.
            Напечатайте адрес векторов b и c и адрес первого элемента векторов b и c.

            Переместите вектор c в вектор b
            Напечатайте адрес вектора b и адрес первого элемента вектора b.

            Какие из адресов изменятся, а какие будут совпадать.
        

        2)  Что будет происходить если сделать вектор a константным.
            Сможем ли мы его переместить?
*/