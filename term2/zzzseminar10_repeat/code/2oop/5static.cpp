#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;


class Something
{
public:
    static int value;
    Something(int x)
    {
        value += x;
    }
};
int Something::value = 10;

int main()
{
    // Статическая переменная общая для всех экземпляров класса:
    Something::value += 10;
    // Что напечатает следующая строка?
    // cout << a.value << endl;

    Something a(15);
    // Что напечатает следующая строка?
    // cout << a.value << endl;

    Something b = {30};
    // Что напечатает следующая строка?
    // cout << b.value << endl;

    Something* c = new Something(40);
    // Что напечатает следующая строка?
    // cout << c->value << endl;
}