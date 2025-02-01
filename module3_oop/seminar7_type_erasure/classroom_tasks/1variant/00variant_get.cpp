#include <iostream>
#include <vector>
#include <variant>
using std::cout, std::endl;

int main()
{
    std::variant<int, double, std::string> v("Cat");
    cout << std::get<std::string>(v) << endl;


    v = 10;
    cout << std::get<int>(v) << endl;


    v = 1.5;
    cout << std::get<double>(v) << endl;

    // cout << std::get<int>(v) << endl; // кинет исключение
}
