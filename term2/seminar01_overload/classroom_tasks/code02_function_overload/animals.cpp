#include <iostream>
using std::cout, std::endl;

struct Cat {};
struct Dog {};
struct Cow {};



void say(Cat a)
{
    cout << "Meow" << endl;
}

void say(Dog a)
{
    cout << "Woof" << endl;
}

void say(Cow a)
{
    cout << "Mooo" << endl;
}


int main()
{
    Cow x;
    say(x);
}