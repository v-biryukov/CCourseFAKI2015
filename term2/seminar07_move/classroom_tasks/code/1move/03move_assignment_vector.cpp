/*
    Перемещать объекты можно как сразу при создании объекта, так и при присваивании.


    В функции moveConstruction в строке:

        std::vector<int> b (std::move(a));

    происходит коструирование объекта b, путём перемещения в него объекта a.
    После этого вектор a станет пустым.



    В функции moveAssignment в строке:

        b = std::move(a);
    
    происходит перемещение объекта a в уже созданный объект b.
    Во время этой операции, содержимое вектора b удалится и заменится содержимым вектора a.
    Вектора a после этой операции станет пустым.

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

void moveConstruction()
{
    std::vector<int> a {10, 20, 30, 40, 50};

    cout << "Move Construction:" << endl;
    cout << "Before move: " << endl;
    cout << "vector a = " << a << endl;
    cout << "vector a: size = " << a.size() << ", capacity = " << a.capacity() << ", pointer = " << &a[0] << endl;


    // Создаём объект b, переместив в него объект a
    std::vector<int> b (std::move(a));


    cout << endl << "After move: " << endl;
    cout << "vector a = " << a << endl;
    cout << "vector b = " << b << endl;
    cout << "vector a: size = " << a.size() << ", capacity = " << a.capacity() << ", pointer = " << &a[0] << endl;
    cout << "vector b: size = " << b.size() << ", capacity = " << b.capacity() << ", pointer = " << &b[0] << endl;
}



void moveAssignment()
{
    std::vector<int> a {10, 20, 30, 40, 50};
    std::vector<int> b {50, 60, 70, 80, 90};

    cout << endl << endl << "Move Assignment:" << endl;
    cout << "Before move: " << endl;
    cout << "vector a = " << a << endl;
    cout << "vector b = " << b << endl;
    cout << "vector a: size = " << a.size() << ", capacity = " << a.capacity() << ", pointer = " << &a[0] << endl;
    cout << "vector b: size = " << b.size() << ", capacity = " << b.capacity() << ", pointer = " << &b[0] << endl;


    // Перемещаем объект a в объект b
    b = std::move(a);


    cout << endl << "After move: " << endl;
    cout << "vector a = " << a << endl;
    cout << "vector b = " << b << endl;
    cout << "vector a: size = " << a.size() << ", capacity = " << a.capacity() << ", pointer = " << &a[0] << endl;
    cout << "vector b: size = " << b.size() << ", capacity = " << b.capacity() << ", pointer = " << &b[0] << endl;
}


int main()
{
    moveConstruction();
    moveAssignment();
}



/*
    Задание:

        1)  Создайте вектора a и b и иницилизируйте их произвольными значениями.
            Напечатайте адрес векторов a и b и адрес первого элемента векторов a и b.

            Переместите вектор b в вектор a
            Напечатайте адрес вектора a и адрес первого элемента вектора a.

            Какие из адресов изменятся, а какие будут совпадать.
        

        2)  Что будет происходить если сделать вектор a константным.
            Сможем ли мы его переместить?
*/