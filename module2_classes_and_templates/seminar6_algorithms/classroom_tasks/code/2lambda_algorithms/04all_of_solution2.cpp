#include <iostream>
#include <vector>
#include <algorithm>
using std::cout, std::endl;

bool containChar(const std::vector<std::string>& vs, char c)
{
    return std::any_of(vs.begin(), vs.end(), [c](std::string_view s){return std::any_of(s.begin(), s.end(), [c](char x){return x == c;});});
}

int main()
{
    std::vector<std::string> vs {"Cat", "Dog", "Ocelot", "Camel", "Caterpillar", "Chameleon", "Iguana", "Bat", "Mouse", "Cow"};

    cout << std::boolalpha;
    cout << containChar(vs, 'a') << endl;
    cout << containChar(vs, 'C') << endl;
    cout << containChar(vs, 'A') << endl;
    cout << containChar(vs, 'x') << endl;
    cout << containChar(vs, 'w') << endl;
}