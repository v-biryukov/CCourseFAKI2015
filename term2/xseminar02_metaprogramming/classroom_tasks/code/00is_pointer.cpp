#include <iostream>
using std::cout, std::endl;


template <typename T>
struct isPointer
{
    static constexpr bool value = false;    
};


template <typename T>
struct isPointer<T*>
{
    static constexpr bool value = true;    
};



int main()
{
    cout << isPointer<char>::value << endl;
    cout << isPointer<float*>::value << endl;


    int a = 100;
    int* p = &a;

    cout << isPointer<decltype(a)>::value << endl;
    cout << isPointer<decltype(p)>::value << endl;
}
