#include <iostream>
#include <string>
using std::cout, std::endl;

int main()
{
    std::string&& r = std::string{"Cat"};
    cout << r << endl;

    r = "Elephant";
    cout << r << endl;
}