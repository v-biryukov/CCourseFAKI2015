/*
    Перегрузка оператора << для вывода на экран

    Напомним, что объект под названием cout имеет тип ostream (сокращение от output stream - выходной поток)
    и хранится в библиотеке iostream в пространстве имён std

    То есть где-то внутри библиотеки iostream объявлена глобальная переменная по имени cout типа ostream
        ostream cout;

    
    Мы можем перегрузить оператор << с первым аргументом типа std::ostream, а вторым аргументом - нашим типом,
    чтобы удобно выводить на экран объекты нашего типа.
*/

#include <iostream>
using std::cout, std::endl;


struct Time 
{
    int minutes;
    int seconds;
};


void operator<<(std::ostream& out, Time t)
{
    out << t.minutes << ":" << t.seconds;
}


int main() 
{
    Time a = {10, 20};
    cout << a;
}


/*
    Задача:

        cout << a;  работает, но
        cout << a << endl; выдаёт ошибку в данной программе.

        Из-за чего это происходит и как исправить эту ошибку?

*/