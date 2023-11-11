#include <iostream>
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
    out << t.minutes << ":" << t.seconds;
    return out;
}


int main() 
{
    Time a = {10, 20};
    Time b = {15, 50};

    cout << a << endl << b << endl;
    cout << a + b << endl;
}


/*
    Задача:

        cout << a;  работает, но
        cout << a << endl; выдаёт ошибку в данной программе.

        Из-за чего это происходит и как исправить эту ошибку?


    Решение:

        Ошибка происходила из-за того, что оператор << ничего не возвращал.
        
        В строке   

            cout << a << endl;

        результат  cout << a  был void и к нему нельзя применить оператор << ещё раз.


        Результат  cout << a  должен быть тоже быть равен cout.
        Но, поскольку глобальный объект cout копировать мы не можем, у нас остаётся единственный выход:
        принимать и возвращать объект cout по ссылке.
*/  