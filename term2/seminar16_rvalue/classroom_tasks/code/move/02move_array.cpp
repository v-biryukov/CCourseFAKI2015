#include <array>
#include <iostream>
using std::cout, std::endl;


std::ostream& operator<<(std::ostream& out, const std::array<int, 5>& a)
{
    for (auto el : a)
        out << el << " ";
    return out;
}


int main()
{
    std::array<int, 5> a = {10, 20, 30, 40, 50};
    std::array<int, 5> b = std::move(a);

    cout << "array a = " << a << endl;
    cout << "array b = " << b << endl;

    cout << "array a: size = " << a.size() << ", pointer = " << a.data() << endl;
    cout << "array b: size = " << b.size() << ", pointer = " << b.data() << endl;
}