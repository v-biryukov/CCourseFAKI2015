#include <iostream>
using std::cout, std::endl;


struct TrueType  { static constexpr bool value = true;   };
struct FalseType { static constexpr bool value = false;  };


template <typename T>
struct IsInt : FalseType {};


template <>
struct IsInt<int> : TrueType {};



int main()
{
    int a = 100;
    int& r = a;
    float b = 1.5;

    cout << IsInt<decltype(a)>::value << endl;
    cout << IsInt<decltype(r)>::value << endl;
    cout << IsInt<decltype(b)>::value << endl;
}
