#include <iostream>
using std::cout, std::endl;


/*
    Ссылки можно и возвращать из функции
    Например, функция increase принимает ссылку, увеличивет то, на что указывает эта ссылка на 1
    и возвращает эту ссылку

    При этом никакого копирование в функцию и из функции не происходит
*/

int& increase(int& a) 
{
    a += 1;
    return a;
}

int main() 
{
    int a = 10;

    cout << "1) a = " << a << endl;

    increase(a);
    cout << "2) a = " << a << endl;

    increase(a) += 7;
    cout << "3) a = " << a << endl;

    increase(increase(increase(a)));
    cout << "4) a = " << a << endl;
}



/*
    Что напечатает данная программа?
*/