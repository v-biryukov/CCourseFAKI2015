#include <iostream>
#include <vector>
#include <algorithm>
using std::cout, std::endl;

int main()
{
    std::vector<std::string> v {"Cat", "Dog", "Ocelot", "Camel", "Caterpillar", "Lion", "Iguana", "Bat", "Mouse", "Oak"};

    cout << std::count_if(v.begin(), v.end(), [](const std::string& el){return el.size() == 3;}) << endl;

    cout << std::count_if(v.begin(), v.end(), [](const std::string& el){return el.size() > 0 && el[0] == 'C';}) << endl;

    cout << std::count_if(v.begin(), v.end(), [](const std::string& el){return el.starts_with("Cat");}) << endl;
}