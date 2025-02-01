#include <iostream>
#include <list>
#include <string>
using std::cout, std::endl;

int main()
{
    std::list<std::string> l {"Cat", "Dog", "Mouse", "Lion" };

    for (std::list<std::string>::iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;


    l.push_front("Tiger");

    for (std::list<std::string>::iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;


    std::list<std::string>::iterator it = l.begin();
    std::advance(it, 3);
    l.insert(it, "Elephant");

    for (std::list<std::string>::iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;




    for (std::list<std::string>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it)
        cout << *it << " ";
    cout << endl;
}