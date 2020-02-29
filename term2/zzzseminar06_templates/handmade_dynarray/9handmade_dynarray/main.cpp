#include <iostream>
#include "9handmade_dynarray.h"

using namespace std;

int main()
{
	Dynarray<int> a = {4, 8, 15, 16, 23, 42};
	Dynarray<string> b = {"Cat", "Dog", "Nutria", "Echidna", "Turtle", "Coati"};

	for (string& s : b)
		s = "[" + s + "]";

	for (const string& s : a)
		cout << s << endl;
}
