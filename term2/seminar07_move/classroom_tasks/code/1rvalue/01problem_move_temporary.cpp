#include <iostream>
#include <string>
#include <vector>
using std::cout, std::endl;


void func(std::string s)
{
    cout << s << endl;
}

int main()
{
    std::vector<std::string> animals {"Axolotl", "Bear", "Cat", "Dog", "Eagle"};
    std::string* p = &animals[4];


    func(animals[0]);
    func(animals[0] + animals[1]);
    func(*p);
    func(animals[0].substr(1, 2));
    func(*(&animals[0] + 2));
}


/*
    Задача:

        В каких из вызовов функции func передаваемые объекты будут копироваться в функцию, а в каких перемещаться?
*/