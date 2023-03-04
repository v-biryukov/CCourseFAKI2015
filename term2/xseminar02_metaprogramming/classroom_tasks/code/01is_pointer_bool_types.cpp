#include <iostream>
using std::cout, std::endl;


struct trueType 
{
    static constexpr bool value = true;    
};

struct falseType
{
    static constexpr bool value = false;    
};


template <typename T>
struct isPointer : falseType {};


template <typename T>
struct isPointer<T*> : trueType {};



int main()
{
    cout << isPointer<char>::value << endl;
    cout << isPointer<float*>::value << endl;


    int a = 100;
    int* p = &a;

    cout << isPointer<decltype(a)>::value << endl;
    cout << isPointer<decltype(p)>::value << endl;
}
