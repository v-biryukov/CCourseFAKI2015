/*
    Параметры в перегруженных операторах

    Так как перегруженные операторы - это просто функции, то и типы входящих параметров могут быть
    такими же как и в обычных функциях. Например, можно передавать аргументы и по сслыке и по константной ссылке.

    Возвращаемое значение тоже может быть любым.

    В данном примере перегружен оператор || для двух времён. Первое время передаётся по ссылке, а второе - по
    константной ссылке. Внутри этого оператора, первое время меняется, а сам оператор возвращает число 123.
*/

#include <iostream>
using std::cout, std::endl;


struct Time 
{
    int minutes;
    int seconds;
};



int operator||(Time& ta, const Time& tb)
{
    cout << "binary operator ||" << endl;

    ta.minutes = tb.seconds;
    ta.seconds = tb.minutes;

    return 123;
}


int main() 
{
    Time a = {20, 10};
    Time b = {40, 50};

    int result = a || b;

    cout << a.minutes << " " << a.seconds << endl;
    cout << result << endl;
}
