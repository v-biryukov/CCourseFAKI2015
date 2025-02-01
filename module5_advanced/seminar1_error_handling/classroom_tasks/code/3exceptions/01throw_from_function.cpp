/*
    Оператор throw последовательно выходит из всех вложенных функций
    пока не достигнет блока try-catch

    Если операторы try и catch не были использованы, то throw выйдет
    из функции main и программа завершится с сообщением:
    
        terminate called after throwing an instance of 'тип аргумента'
*/


#include <iostream>
using std::cout, std::endl;

void second()
{
    cout << "Second function start" << endl;
    throw 123;
    cout << "Second function finish" << endl;
}

void first()
{
    cout << "First function start" << endl;
    second();
    cout << "First function finish" << endl;
}

int main()
{
    cout << "Main start" << endl;
    first();
    cout << "Main finish" << endl;
}