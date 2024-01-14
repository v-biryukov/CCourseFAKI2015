#include <iostream>
#include <string>
#include <array>
#include <vector>
using std::cout, std::endl;
using namespace std::string_literals;


template <typename T>
using triplet = std::array<T, 3>;


template <typename T, typename U>
using info = std::pair<std::pair<std::string, T>, std::vector<U>>;


int main()
{
    triplet<int> t {10, 20, 30};
    cout << t[0] << " " << t[1] << " " << t[2] << endl;


    info<int, std::string> a {{"Alice"s, 100}, {"Cat"s, "Dog"s, "Mouse"s, "Elephant"s}};

    for (int i = 0; i < a.second.size(); ++i)
    {
        cout << a.second[i] << " ";
    }
    cout << endl;


    info<std::vector<std::string>, int> b {{"Alice"s, {"Red"s, "Blue"s, "Yellow"s}}, {10, 20, 30, 40}};

    for (int i = 0; i < b.first.second.size(); ++i)
    {
        cout << b.first.second[i] << " ";
    }
    cout << endl;

}