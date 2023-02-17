#include <iostream>
#include <string>
#include <utility>
using std::cout, std::endl;


void func(std::string& s)
{
    cout << "Pass by lvalue reference" << endl;
}

void func(std::string&& s)
{
    cout << "Pass by rvalue reference" << endl;
    s = "Mouse";
}

int main()
{
    std::string a {"Cat"};

    cout << a << endl;
    func(std::move(a));
    cout << a << endl;
}


/*
    Да, изменится.
    Хоть мы и передаём в функцию rvalue-ссылку на объект, это всё равно ссылка.
    (под капотом это будет указатель на наш объект).
    Поэтому при изменении объекта в функции, этот объект вне функции тоже изменится.
*/