#include <iostream>
#include <list>

using std::cout;
using std::endl;

int main() {
    std::list<int> a {64, 21, 50, 7, 15, 2, 73, 99};

    // Для связного списка нет оператора[] (доступа к элементу)
    // Код ниже не сработает
    // cout << a[1] << endl;


    // Нужно использовать итераторы:
    for (std::list<int>::iterator it = a.begin(); it != a.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Чтобы добавить в начало и конец
    a.push_front(123);
    a.push_back(987);

    // Напечатаем ещё раз:
    for (std::list<int>::iterator it = a.begin(); it != a.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;


    // Чтобы удалить элемент по итератору:
    // (удалим элемент с индексом 2)
    std::list<int>::iterator it = a.begin();
    it++;
    it++;
    a.erase(it);

    // Напечатаем ещё раз:
    for (int el : a)
    {
        cout << el << " ";
    }
    cout << endl;


    // Но если вы хотите удалить элемент в цикле, то так не сработает:
    // (например, хотим удалить все чётные элементы)
    // Почему код ниже не сработает?
    /*
    for (std::list<int>::iterator it = a.begin(); it != a.end(); it++)
    {
        if (*it % 2 == 0)
        {
            a.erase(it);
        }

    }
    */

    // Правильно удалять так:
    for (std::list<int>::iterator it = a.begin(); it != a.end();) {
        if (*it % 2 == 0) {
            it = a.erase(it);
            // Функция erase возвратит итератор на следующий элемент
        }
        else {
            it++;
        }
    }

    // Напечатаем ещё раз:
    for (int el : a) {
        cout << el << " ";
    }
    cout << endl;


    /* Задачи:
        1) Напишите функцию, которая будет принимать на вход список из чисел и возвращать сумму чисел

        2) Напишите функцию, которая будет принимать на вход список из слов (элементов std::string)
           и удалять из него все слова короче 5 символов

    */

}