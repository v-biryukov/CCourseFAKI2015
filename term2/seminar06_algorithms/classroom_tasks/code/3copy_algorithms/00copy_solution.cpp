#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
    std::vector<std::string> vs {"Cat", "Dog", "Ocelot", "Camel", "Caterpillar", "Chameleon", "Iguana", "Bat", "Mouse", "Cow"};

    int numStartedWithC = std::count_if(vs.begin(), vs.end(), [](std::string_view s){return s.size() > 0 && s[0] == 'C';});
    std::vector<std::string> vsc(numStartedWithC);
    std::copy_if(vs.begin(), vs.end(), vsc.begin(), [](std::string_view s){return s.size() > 0 && s[0] == 'C';});
    printVector(vsc);
}
