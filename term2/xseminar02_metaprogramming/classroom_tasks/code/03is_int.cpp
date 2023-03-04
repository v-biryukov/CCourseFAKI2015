#include <iostream>
using std::cout, std::endl;


struct trueType  { static constexpr bool value = true;   };
struct falseType { static constexpr bool value = false;  };


template <typename T>
struct isInt : falseType {};


template <>
struct isInt<int> : trueType {};



int main()
{
    int a = 100;
    int& r = a;
    float b = 1.5;

    cout << isInt<decltype(a)>::value << endl;
    cout << isInt<decltype(r)>::value << endl;
    cout << isInt<decltype(b)>::value << endl;
}
