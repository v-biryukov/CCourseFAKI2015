#include <iostream>
using std::cout, std::endl;


template <typename T>
struct IsPointer
{
    static constexpr bool value = false;    
};


template <typename T>
struct IsPointer<T*>
{
    static constexpr bool value = true;    
};



int main()
{
    cout << IsPointer<char>::value << endl;
    cout << IsPointer<float*>::value << endl;


    int a = 100;
    int* p = &a;

    cout << IsPointer<decltype(a)>::value << endl;
    cout << IsPointer<decltype(p)>::value << endl;
}
