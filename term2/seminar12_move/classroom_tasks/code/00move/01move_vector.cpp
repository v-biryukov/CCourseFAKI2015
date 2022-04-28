#include <vector>
#include <iostream>
using std::cout, std::endl;



// Вспомагательная функция для вывода вектора на экран
std::ostream& operator<<(std::ostream& out, const std::vector<int>& v)
{
    for (auto el : v)
        out << el << " ";
    return out;
}


/*
    Вектор можно переместить с помощью std::move
*/

int main()
{
    std::vector<int> a = {10, 20, 30, 40, 50};
    std::vector<int> b = std::move(a);

    cout << "vector a = " << a << endl;
    cout << "vector b = " << b << endl;

    cout << "vector a: size = " << a.size() << ", capacity = " << a.capacity() << ", pointer = " << a.data() << endl;
    cout << "vector b: size = " << b.size() << ", capacity = " << b.capacity() << ", pointer = " << b.data() << endl;
}


/*
    Задание:

        1)  Создайте новый вектор c и иницилизируйте его
            Напечатайте адрес вектора и адрес первого элемента вектора

            Переместите вектор c в вектор b
            Напечатайте адрес вектора b и адрес первого элемента вектора b
        

        2)  Что будет происходить если сделать вектор a константным
            Сможем ли мы его переместить?
*/