#include <iostream>
using std::cout;
using std::endl;




int main()
{
    // Используется для приведения базовых типов друг в друга
    float a = 5.4;
    int b = static_cast<int>(a);
    cout << "b = " << b << endl;


    // Используется для приведение указателей любых типов к типу void* и наоборот
    int* p = &b;
    void* pv = static_cast<void*>(p);

}  
