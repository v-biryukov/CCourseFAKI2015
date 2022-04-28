#include <iostream>
#include <string>
using std::cout, std::endl;

template <typename T>
std::string type(T x) {
    return "Other Type";
}

template<>
std::string type(int x) {
    return "int";
}

template<>
std::string type(float x) {
    return "float";
}

template<>
std::string type(double x) {
    return "double";
}

template<>
std::string type(std::string x) {
    return "string";
}

template<>
std::string type(const char* x) {
    return "C-string";
}

struct Date {
    int day, month, year;
};

template<>
std::string type(Date x) {
    return "Date";
}

int main() {
    cout << type(5.2) << endl;
    cout << type("Hello") << endl;
}