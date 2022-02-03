#include <string>
#include <iostream>
using std::cout, std::endl;



int main()
{
    std::string a = "Sapere Aude";
    std::string b = std::move(a);

    cout << "array a = " << a << endl;
    cout << "array b = " << b << endl;

    cout << "array a: size = " << a.size() << ", pointer = " << a.data() << endl;
    cout << "array b: size = " << b.size() << ", pointer = " << b.data() << endl;
}