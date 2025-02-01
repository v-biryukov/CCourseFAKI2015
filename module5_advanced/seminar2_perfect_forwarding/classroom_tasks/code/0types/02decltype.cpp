/*
    Всё, что было сделано с помощью decltype в предыдущем примере можно сделать и с auto.

    Но вывод типа у auto и decltype очень сильно отличается.

    auto отбрасывает ссылки и const, преобразует массивы в указатели и т. д.
    decltype выводит тип с учётом ссылок, const и т. д.
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "type_name.hpp"
using std::cout, std::endl;


int main()
{
    cout << "1) Testing decltype:" << endl;

    int a = 10;
    int& b = a;
    const int& d = 30;

    cout << typeName<decltype(5)>() << endl;
    cout << typeName<decltype(a)>() << endl;
    cout << typeName<decltype(b)>() << endl;
    cout << typeName<decltype(c)>() << endl;
    cout << typeName<decltype(d)>() << endl;


    cout << endl << "2) auto vs decltype:" << endl;

    auto x = d;
    decltype(d) y = d;

    cout << typeName<decltype(x)>() << endl;
    cout << typeName<decltype(y)>() << endl;



    cout << endl << "3) decltype(auto):" << endl;
    decltype(auto) z = d;
    cout << typeName<decltype(z)>() << endl;
}



/*
    Проверьте, сохраняет ли decltype тип у rvalue-ссылки.
*/