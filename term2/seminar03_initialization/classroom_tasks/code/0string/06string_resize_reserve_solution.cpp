#include <iostream>
#include <string>
using std::cout, std::endl;


int main()
{
    std::string s;

    s.reserve(300);

    for (int i = 0; i < 300; ++i)
    {
        s += 'a' + i % 26;
        cout << "Size = " << s.size() << " Capacity = " << s.capacity() << endl;
    }

    cout << s << endl;
}
