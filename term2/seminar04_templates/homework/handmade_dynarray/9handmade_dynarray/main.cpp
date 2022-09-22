#include <iostream>
#include "9handmade_dynarray.h"

using std::cout, std::endl, std::string;

int main()
{
    Dynarray<int> a = {4, 8, 15, 16, 23, 42};
    for (const int& s : a)
        cout << s << endl;

    Dynarray<string> b = {"Cat", "Dog", "Nutria", "Echidna", "Turtle", "Coati"};

    for (string& s : b)
        s += "s";

    for (const string& s : b)
        cout << s << endl;
}
