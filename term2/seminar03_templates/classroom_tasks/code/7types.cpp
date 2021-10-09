#include <iostream>
#include <string>
using namespace std;

template <typename T>
string type(T x) {
	return "Other Type";
}

template<>
string type(int x) {
	return "int";
}

template<>
string type(float x) {
	return "float";
}

template<>
string type(double x) {
	return "double";
}

template<>
string type(string x) {
	return "string";
}

template<>
string type(const char* x) {
	return "C-string";
}

struct Date {
	int day, month, year;
};

template<>
string type(Date x) {
	return "Date";
}

int main() {
	cout << type(5.2) << endl;
	cout << type("Hello") << endl;
}