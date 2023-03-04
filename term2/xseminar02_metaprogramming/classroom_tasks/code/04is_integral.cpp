#include <iostream>
using std::cout, std::endl;


struct trueType  { static constexpr bool value = true;   };
struct falseType { static constexpr bool value = false;  };


template <typename T>
struct isIntegral : falseType {};


template <> struct isIntegral<char> : TrueType {};
template <> struct isIntegral<short> : TrueType {};
template <> struct isIntegral<int> : TrueType {};
template <> struct isIntegral<long> : TrueType {};
template <> struct isIntegral<long long> : TrueType {};
template <> struct isIntegral<unsigned char> : TrueType {};
template <> struct isIntegral<unsigned short> : TrueType {};
template <> struct isIntegral<unsigned int> : TrueType {};
template <> struct isIntegral<unsigned long> : TrueType {};
template <> struct isIntegral<unsigned long long> : TrueType {};



int main()
{
    cout << isIntegral<int>::value << endl;
    cout << isIntegral<float>::value << endl;
    cout << isIntegral<char>::value << endl;
    cout << isIntegral<int*>::value << endl;
    cout << isIntegral<unsigned long long>::value << endl;
    cout << isIntegral<int[]>::value << endl;
}
