#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string_view>
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


    std::partition(vi.begin(), vi.end(), [](int x){return x % 2 == 0;});
    std::partition(vs.begin(), vs.end(), [](std::string_view s){return s[0] == 'C';});

    printVector(vi);
    printVector(vs);
}