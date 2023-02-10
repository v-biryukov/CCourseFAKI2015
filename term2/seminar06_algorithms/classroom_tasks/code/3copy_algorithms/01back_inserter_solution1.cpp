#include <iostream>
#include <vector>
#include <string>
#include <string_view>
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
    
    std::vector<std::string> vsc;
    std::copy_if(vs.begin(), vs.end(), std::back_inserter(vsc), [](std::string_view s){return s.size() > 0 && s[0] == 'C';});
    printVector(vsc);
}
