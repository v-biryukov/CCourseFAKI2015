#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>
#include <cctype>
using std::cout, std::endl;

template <typename T>
void printVector(const std::vector<T>& v)
{
    for (typename std::vector<T>::const_iterator it = v.cbegin(); it != v.cend(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    std::vector<int> vi {81, 82, 78, 36, 39, 96, 11, 58, 15, 48};
    std::vector<std::string> vs {"Cat", "Dog", "Ocelot", "Camel", "Caterpillar", "Chameleon", "Iguana", "Bat", "Mouse", "Cow"};

    printVector(vi);
    printVector(vs);

    cout << std::boolalpha;
    cout << std::all_of(vi.begin(), vi.end(), [](int el){return el >= 10 && el < 100;}) << endl;
    cout << std::all_of(vs.begin(), vs.end(), [](std::string_view s){return s.size() > 0 && std::isupper(s[0]);}) << endl;
    
}