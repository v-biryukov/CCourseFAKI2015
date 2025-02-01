/*
    Копирование и перемещение std::unique_ptr

    Умные указатели std::unique_ptr нельзя копировать и присваивать:

        std::unique_ptr<int> a {new int {123}};

        std::unique_ptr<int> b = a; // Ошибка

        std::unique_ptr<int> c;
        c = a;                      // Ошибка


    Но умные указатели std::unique_ptr можно перемещать.
    Перемещать можно как при создании объектов (конструктор перемещения):


        std::unique_ptr<int> a {new int {123}};
        std::unique_ptr<int> b = std::move(a);

    Так и при присваивании (присваивание перемещения):

        std::unique_ptr<int> a {new int {123}};
        std::unique_ptr<int> b;
        b = std::move(a);


    Метод get объекта std::unique_ptr возвращает адрес, на который хранит указатель.
*/



#include <memory>
#include <iostream>
using std::cout, std::endl;

int main()
{
    std::unique_ptr<int> a {new int {123}};
    cout << "unique_ptr a address = " << a.get() << endl;


    cout << "Moving a to b" << endl;
    std::unique_ptr<int> b = std::move(a);

    cout << "unique_ptr a address = " << a.get() << endl;
    cout << "unique_ptr b address = " << b.get() << endl;
}