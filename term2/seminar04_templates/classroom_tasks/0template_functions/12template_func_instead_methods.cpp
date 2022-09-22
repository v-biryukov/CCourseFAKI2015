/*
    Тут мы создали шаблонную функцию sayNTimes, которая будет вызывать метод say n раз.
    Для этого у типа T должен быть определён метод say.

    Мы, конечно, могли сделать метод sayNTimes, но тогда нам бы пришлось повторить этот
    метод во всех трёх классах.
*/


#include <iostream>
using std::cout, std::endl;



struct Cat {void say() {cout << "Meow";}};
struct Dog {void say() {cout << "Woof";}};
struct Cow {void say() {cout << "Mooo";}};


template <typename T>
void sayNTimes(T a, int n) 
{
    for (int i = 0; i < n; ++i)
    {
        a.say();
        cout << " ";
    }
    cout << endl;
}


int main() 
{
    Cat a;
    Dog b;
    Cow c;

    sayNTimes(a, 7);
    sayNTimes(b, 2);
    sayNTimes(c, 1);   
}