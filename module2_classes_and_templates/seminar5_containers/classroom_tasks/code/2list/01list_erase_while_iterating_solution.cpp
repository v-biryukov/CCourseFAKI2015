#include <iostream>
#include <list>
#include <string>
using std::cout, std::endl;

int main()
{
    std::list<int> l {10, 25, 30, 41, 59, 62, 78};


    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;



    for (std::list<int>::iterator it = l.begin(); it != l.end();)
    {
        if (*it % 2 == 1)
        {
            it = l.erase(it);
        }
        else
        {
            ++it;
        }
    }


    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;
}


/*
    Задача:

        Исправьте код данной программы.
        Используйте то, что метод erase возвращает итератор на следующий после удалённого элемент.
*/
