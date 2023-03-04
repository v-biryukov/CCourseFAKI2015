#include <iostream>
using std::cout, std::endl;


struct trueType  { static constexpr bool value = true;   };

struct falseType { static constexpr bool value = false;  };


template <typename T>
struct isReference : falseType {};


template <typename T>
struct isReference<T&> : trueType {};



int main()
{
    cout << isReference<char>::value << endl;
    cout << isReference<float&>::value << endl;


    int a = 100;
    int& r = a;

    cout << isReference<decltype(a)>::value << endl;
    cout << isReference<decltype(r)>::value << endl;
}
