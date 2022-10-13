/*
    Печать булевых переменных как true и false

    По умолчанию, булевые переменные печатаются как 0 или 1.
    Чтобы они печатались как false или true нужно потоку передать модификатор std::boolalpha.    
*/


#include <iostream>
#include <iomanip>
using std::cout, std::endl;

int main()
{
    bool a = true;
    bool b = false;

    cout << a << " " << b << endl;

    cout << std::boolalpha;
    cout << a << " " << b << endl;
}