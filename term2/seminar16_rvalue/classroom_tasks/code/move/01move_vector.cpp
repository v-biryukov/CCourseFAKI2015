#include <vector>
#include <iostream>
using std::cout, std::endl;


std::ostream& operator<<(std::ostream& out, const std::vector<int>& v)
{
    for (auto el : v)
        out << el << " ";
    return out;
}


int main()
{
    std::vector<int> a = {10, 20, 30, 40, 50};
    std::vector<int> b = std::move(a);

    cout << "vector a = " << a << endl;
    cout << "vector b = " << b << endl;

    cout << "vector a: size = " << a.size() << ", capacity = " << a.capacity() << ", pointer = " << a.data() << endl;
    cout << "vector b: size = " << b.size() << ", capacity = " << b.capacity() << ", pointer = " << b.data() << endl;
}