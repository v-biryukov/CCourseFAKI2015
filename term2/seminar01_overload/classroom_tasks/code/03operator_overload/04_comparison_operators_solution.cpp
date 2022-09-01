#include <iostream>
using std::cout, std::endl;


/*
    Помимо арифметических операторов можно перегружать и операторы сравнения (и многие другие операторы)
    Желательно, чтобы операторы сравнения возвращали bool
*/


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


bool operator>(Time ta, Time tb)
{
    bool result = false;

    if (ta.minutes > tb.minutes)
        result = true;
    else if (ta.minutes == tb.minutes && ta.seconds > tb.seconds)
        result = true;
    
    return result;
}


bool operator==(Time ta, Time tb)
{
    bool result = false;
    if (ta.minutes == tb.minutes && ta.seconds == tb.seconds)
        result = true;

    return result;
}

bool operator!=(Time ta, Time tb)
{
    return !(ta == tb);
}


bool operator>=(Time ta, Time tb)
{
    return ta > tb || ta == tb;
}


bool operator<(Time ta, Time tb)
{
    return !(ta >= tb);
}


bool operator<=(Time ta, Time tb)
{
    return !(ta > tb);
}





int main() 
{
    Time a = {10, 20};
    Time b = {10, 40};
    Time c = {0,  20};

    cout << std::boolalpha;
    cout << (a == b) << endl;
    cout << (a != b) << endl;

    cout << (a < b) << endl;
    cout << (a <= b) << endl;
    cout << (a > b) << endl;
    cout << (a >= b) << endl;
    cout << (a + c >= b) << endl;
}


/*

    Задача:

        1)  Заметьте, что при выводе на экран сравнение было взято в скобки
                cout << (a > b) << endl;

            Что будет, если эти скобки не писать и почему
                cout << a > b << endl;
            
            Ошибка происходит из-за того, что приоритет операции << выше, чем у операций сравнения
            В результате сначала проводится
                cout << a
            затем получившийся объект сравнивается с b. Это и приводит к ошибке.
*/