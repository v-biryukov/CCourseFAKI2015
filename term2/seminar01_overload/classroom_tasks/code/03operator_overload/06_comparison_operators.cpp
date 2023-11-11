/*
    Перегрузка операторов сравнения

    Перегруженные операторы сравнения. Желательно, чтобы они возвращали bool.
*/

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


bool operator>(Time ta, Time tb)
{
    bool result = false;

    if (ta.minutes > tb.minutes)
        result = true;
    else if (ta.minutes == tb.minutes && ta.seconds > tb.seconds)
        result = true;
    
    return result;
}


int main() 
{
    Time a = {10, 20};
    Time b = {10, 40};
    Time c = {0,  20};

    cout << std::boolalpha;
    cout << (a > b) << endl;
    cout << (b > a) << endl;
    cout << (a + c > b) << endl;
}


/*

    Задачи:

        1)  Заметьте, что при выводе на экран сравнение было взято в скобки
                cout << (a > b) << endl;

            Что будет, если эти скобки не писать и почему
                cout << a > b << endl;
        
        
        2)  Напишите перегруженные операторы <  >=  <=  ==  !=  для сравнения объектов структур типа Time друг с другом.
            Все эти операторы можно написать, используя уже написанный оператор > и не используя поля minutes и seconds
            в этих операторах.

*/