/*
    В функцию, которая принимает объект по значению, можно копировать объект, а можно его и перемещать.
    Например, в данном примере функция func принимает строку по значению

    Мы можем скопировать строку в эту функцию вот так:

        func(a);

    А можем переместить строку в эту функцию вот так:

        func(std::move(b));
*/

#include <iostream>
#include <utility>
#include <string>
using std::cout, std::endl;


void func(std::string s)
{
    cout << "Inside func: " << s << endl;
}


int main()
{
    std::string a {"Cat"};
    func(a);
    cout << "After  func: " << a << endl;


    std::string b {"Dog"};
    func(std::move(b));
    cout << "After  func: " << b << endl;
}