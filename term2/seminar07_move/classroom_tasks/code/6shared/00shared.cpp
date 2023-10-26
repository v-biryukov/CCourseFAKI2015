/*
    Другой тип умных указателей -- shared_ptr
    Указатель unique_ptr должен указывать на объект в Куче в одиночку

    В отличии от этого несколько умных указателей shared_ptr могут указывать на один объект в куче
    Для этого указателя есть также функция, которая его создаёт: make_shared
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::cout, std::endl;


int main()
{
    std::shared_ptr<int> p1 {new int{123}};
    std::shared_ptr<int> p2 = p1;
    std::shared_ptr<int> p3 = p1;
    std::shared_ptr<int> p4 = p2;

    cout << *p1 << endl;
    cout << *p2 << endl;
    cout << *p3 << endl;
    cout << *p4 << endl;


    auto q1 = std::make_shared<std::string>("Sapere Aude");
    auto q2 = q1;
    auto q3 = q1;
    auto q4 = q2;

    cout << *q1 << endl;
    cout << *q2 << endl;
    cout << *q3 << endl;
    cout << *q4 << endl;
}


/*
    Задачи:

        1) Создадите shared_ptr на объект типа float равный 12.3

        2) Создадите shared_ptr на объект типа std::vector, содержащий такие числа типа int {5, 5, 5, 5}

        3) Создадите shared_ptr на объект типа std::vector, содержащие следующие
        строки std::string: {"Dog", "Bear", "Elephant", "Bird"}
*/