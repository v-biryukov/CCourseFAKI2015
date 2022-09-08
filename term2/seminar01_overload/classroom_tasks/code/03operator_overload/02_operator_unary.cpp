#include <iostream>
using std::cout, std::endl;


/*
    Помимо перегрузки операторов, принимающих 2 аргумента (бинарных)
    можно перегружать и унарные операторы - принимающие один аргумент

    При этом, так как operator+ это функция, то работает перегрузка функций
*/


struct Time 
{
    int minutes;
    int seconds;
};

Time operator+(Time ta, Time tb)
{
    cout << "binary operator +" << endl;

    Time result = ta;
    result.seconds += 60 * tb.minutes + tb.seconds;
    
    result.minutes += (result.seconds / 60);
    result.seconds %= 60;

    return result;
}

Time operator+(Time t)
{
    cout << "unary operator +" << endl;

    return t;
}


int main() 
{
    Time a = {20, 10};
    Time b = {40, 30};

    Time c = a + b;
    Time d = +a;

    cout << c.minutes << " " << c.seconds << endl;
    cout << d.minutes << " " << d.seconds << endl;
}
