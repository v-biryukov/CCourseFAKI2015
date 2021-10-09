#include <iostream>
#include "String.h"
using std::cout;
using std::endl;


int main() {
	cout << "Creating Strings" << endl;
	String a {"Cat"};
	String b {"Dog"}; 
	String c {"Axolotl"};
	String d {"Cat"};
	String e {"Cat2"};
	coit << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "e = " << e << endl;

	cout << "Testing Summation" << endl;
	String x = a + b;
	cout << "x = a + b; x = " << x << endl;

	x += c;
	cout << "x += c; x = " << x << endl;


	cout << "Testing Constructors" << endl;
	cout << "a + \"abc\" = " <<  a + "abc" << endl;
	cout << "a + 'a' = " <<  a + 'a' << endl;


	cout << "Testing Comparison operators" << endl;
	cout << d << " == " << a << " : " << (d == a) << endl;
	cout << c << " == " << a << " : " << (c == a) << endl;
	cout << a << " >  " << b << " : " << (a > b)  << endl;
	cout << a << " <  " << b << " : " << (a < b)  << endl;
	cout << a << " <  " << d << " : " << (a < d)  << endl;
	cout << a << " <= " << d << " : " << (a <= d) << endl;
	cout << a << " <  " << e << " : " << (a < e)  << endl;
	cout << a << " <= " << e << " : " << (a <= e) << endl;

	cout << "Testing Index operators" << endl;
	cout << "b[2]  = " << b[2] << endl;
	cout << "b[4]  = " << b[4] << endl;
	cout << "b.at(2)  = " << b.at(2) << endl;
	cout << "b.at(4)  = " << b.at(4) << endl;
}
