#include <iostream>
#include <string>
using std::cout, std::cin, std::endl;


int main()
{
    std::string s;
    cin >> s;

    size_t id1 = s.find('.', 0);
    size_t id2 = s.find('.', id1 + 1);
    cout << s.substr(id1 + 1, id2 - id1 - 1) << endl;
}