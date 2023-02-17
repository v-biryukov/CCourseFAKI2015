/*
    В библиотеки iomanip содержатся специальные функции, для работы с потоками ostream

        setw  -  установить минимальный размер в символах для печати следующего объекта
        setfill  -  если размер печати меньше минимального, то замостить оставшееся соответствующим символом

        setprecision  -  установить точность (для вещественных чисел)
*/

#include <iostream>
#include <iomanip>
using std::cout, std::endl;


struct Time 
{
    int minutes;
    int seconds;
};


Time operator+(Time ta, Time tb)
{
    Time result = ta;
    result.seconds += 60 * tb.minutes + tb.seconds;
    
    result.minutes += (result.seconds / 60);
    result.seconds %= 60;

    return result;
}


std::ostream& operator<<(std::ostream& out, Time t)
{
    out << std::setfill('0') << std::setw(2) << t.minutes << ":" << 
           std::setfill('0') << std::setw(2) << t.seconds;
    return out;
}


int main() 
{
    Time a = {1, 5};
    Time b = {4, 20};

    cout << a << endl << b << endl;
    cout << a + b << endl;
}


