#include <iostream>
using std::cout, std::endl;


struct TrueType  { static constexpr bool value = true;   };

struct FalseType { static constexpr bool value = false;  };


template <typename T>
struct IsReference : FalseType {};


template <typename T>
struct IsReference<T&> : TrueType {};



int main()
{
    cout << IsReference<char>::value << endl;
    cout << IsReference<float&>::value << endl;


    int a = 100;
    int& r = a;

    cout << IsReference<decltype(a)>::value << endl;
    cout << IsReference<decltype(r)>::value << endl;
}
