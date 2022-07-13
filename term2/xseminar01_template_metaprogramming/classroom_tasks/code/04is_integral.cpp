#include <iostream>
using std::cout, std::endl;


struct TrueType  { static constexpr bool value = true;   };
struct FalseType { static constexpr bool value = false;  };


template <typename T>
struct IsIntegral : FalseType {};


template <> struct IsIntegral<char> : TrueType {};
template <> struct IsIntegral<short> : TrueType {};
template <> struct IsIntegral<int> : TrueType {};
template <> struct IsIntegral<long> : TrueType {};
template <> struct IsIntegral<long long> : TrueType {};
template <> struct IsIntegral<unsigned char> : TrueType {};
template <> struct IsIntegral<unsigned short> : TrueType {};
template <> struct IsIntegral<unsigned int> : TrueType {};
template <> struct IsIntegral<unsigned long> : TrueType {};
template <> struct IsIntegral<unsigned long long> : TrueType {};



int main()
{
    cout << IsIntegral<int>::value << endl;
    cout << IsIntegral<float>::value << endl;
    cout << IsIntegral<char>::value << endl;
    cout << IsIntegral<int*>::value << endl;
    cout << IsIntegral<unsigned long long>::value << endl;
    cout << IsIntegral<int[]>::value << endl;
}
