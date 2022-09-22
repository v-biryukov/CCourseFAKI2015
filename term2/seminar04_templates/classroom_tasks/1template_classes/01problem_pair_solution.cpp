#include <iostream>
#include <string>
using std::cout, std::endl;

template <typename T, typename U>
struct Pair
{
    T first;
    U second;

    Pair(const T& f, const U& s) : first{f}, second{s} {}

    bool operator<(const Pair r) const
    {
        if (first == r.first)
            return second < r.second;
        return first < r.first;
    }

    bool operator>(const Pair r) const
    {
        if (first == r.first)
            return second > r.second;
        return first > r.first;
    }

    bool operator==(const Pair r) const
    {
        return first == r.first && second == r.second;
    }

    bool operator>=(const Pair r) const
    {
        return !(*this < r);
    }

    bool operator<=(const Pair r) const
    {
        return !(*this > r);
    }
};


int main()
{
    Pair a {5, std::string("Cat")};
    cout << a.first << " " << a.second << endl;

    cout << std::boolalpha;
    cout << (a > Pair{5, std::string("Dog")}) << endl;
    cout << (a > Pair{5, std::string("Ant")}) << endl;
}