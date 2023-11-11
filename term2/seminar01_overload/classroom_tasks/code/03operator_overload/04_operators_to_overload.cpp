/*
    Какие операторы вообще можно перегружать?
    
    На самом деле можно перегрузить почти все операторы, которые встречаются в языке C.
    Даже включая логические операторы (&& || !) и побитовые операторы (& | ^ ~ << >>).

    Но нельзя перегружать свои новые комбинация значков, которые не всречаются в C и C++.
    Например, если вы придумали свой новый оператор -< и хотите использовать его в коде (a -< b),
    то так сделать не получится. Такой новый оператор на существует в языке и перегрузить его не получится.
*/

#include <iostream>
using std::cout, std::endl;


struct Time 
{
    int minutes;
    int seconds;
};

void operator+(Time ta, Time tb)
{
    cout << "binary operator +" << endl;
}

void operator+=(Time ta, Time tb)
{
    cout << "binary operator +=" << endl;
}

void operator%(Time ta, Time tb)
{
    cout << "binary operator %" << endl;
}

void operator!=(Time ta, Time tb)
{
    cout << "binary operator !=" << endl;
}

void operator&&(Time ta, Time tb)
{
    cout << "binary operator &&" << endl;
}

void operator<<(Time ta, Time tb)
{
    cout << "binary operator <<" << endl;
}

void operator-(Time ta)
{
    cout << "unary operator -" << endl;
}

void operator*(Time ta)
{
    cout << "unary operator *" << endl;
}

void operator!(Time ta)
{
    cout << "unary operator !" << endl;
}


int main() 
{
    Time a = {10, 10};
    Time b = {20, 20};
    Time c = {30, 30};

    a + b;
    a * b;
    a += b;
    a % b;
    a != b;
    a && b;
    a << b;
    -a;
    *a;
    !a;
}
