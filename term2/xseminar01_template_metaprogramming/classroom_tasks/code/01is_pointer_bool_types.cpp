#include <iostream>
using std::cout, std::endl;


struct TrueType 
{
    static constexpr bool value = true;    
};

struct FalseType
{
    static constexpr bool value = false;    
};


template <typename T>
struct IsPointer : FalseType {};


template <typename T>
struct IsPointer<T*> : TrueType {};



int main()
{
    cout << IsPointer<char>::value << endl;
    cout << IsPointer<float*>::value << endl;


    int a = 100;
    int* p = &a;

    cout << IsPointer<decltype(a)>::value << endl;
    cout << IsPointer<decltype(p)>::value << endl;
}
