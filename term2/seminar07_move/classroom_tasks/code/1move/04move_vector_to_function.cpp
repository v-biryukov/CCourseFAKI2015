/*
    Перемещать объекты можно и при передаче в функцию, если функция принимает объект по значению.
    
    В строке

        func(a);

    происходит копирование вектора в функцию. При этом копируется как сам объект, так и его элементы, хранящиеся в куче.


    В строке

        func(std::move(a));

    происходит перемещение вектора в функцию. При этом в функцию копируется только сам объект (указатель, размер и вместимость).
    После этой строки, вектор a в функции main станет пустым.
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


void func(std::vector<int> v)
{
    cout << endl << "vector v = " << v << endl;
    cout << "vector address: " << &v << ", vector element address: " << &v[0] << endl;
}


int main()
{
    std::vector<int> a {10, 20, 30, 40, 50};

    cout << "vector a = " << a << endl;
    cout << "vector address: " << &a << ", vector element address: " << &a[0] << endl;


    // Копируем вектор a в функцию
    func(a);


    // Перемещаем вектор a в функцию
    func(std::move(a));
}


/*
    Задачи:

        1)  Что напечатает данная программа? Какие адреса будут совпадать?


        2)  Чему будет равен объект a, после того, как мы его переместили в функцию?
*/