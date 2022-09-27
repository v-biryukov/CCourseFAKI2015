#include <iostream>

/*
    Все переменные/функции/структуры/классы стандартной библиотеки языка C++ содержатся в пространстве имён std
    Рассмотрим, например, глобальную переменную cout, определённую в библиотеке iostream в пространстве имён std.

    К этой переменной можно применять оператор <<
        cout << объект
    В результате этой операции объект напечатается на экран (если он может напечататься)
    Результат оператора << также является cout, поэтому можно применять << несколько раз:



    Например это выражение:   cout << "Hello " << "World" << "\n";

        1)  Сначала напечатается "Hello " и на место  cout << "Hello "  подставится  cout
            Получтся cout << "World" << "\n";

        2)  Потом напечатется "World" и на место  cout << "World"  подставится  cout
            Получтся cout << "\n";

        3)  В конце напечатается перенос строки
*/



int main() 
{
    std::cout << "Hello World\n";
    std::cout << 5 << "\n";

    int x = 10;
    std::cout << 5 << "\n";
}


/*
    Задачи:

        1)  Напечатайте на экран число 1.4, используя cout  (количество печатаемых знаков после запятой неважно)
            Обратите внимание, что при печати с cout не нужно указывать спецификатор типа как в printf.
            cout сам понимает объект какого типа ему передаётся

        2)  Напечатайте фразу "I am x years old", только за место x нужно подставить значение
            переменной x. В данной задаче получится "I am 10 years old". Используйте cout.

        3)  Напечатайте на экран числа от 1 до 20, разделённые пробелом. Используйте cout

        4)  Вместо \n для переноса строки можно использовать endl - специальный объект из
            пространства имён std.
            Если мы передаём его объекту cout через оператор << то печатается перенос строки
            
            Замените все переносы строк с \n на endl
            std::cout << 5 << "\n";  -->  std::cout << 5 << std::endl;


            На самом деле std::endl работает медленней, чем \n, так как он помимо печати делает flush
            Поэтому, если важна скорость печати в буфер, то лучше использовать \n


        5)  Что будет если не написать std:: перед одним из cout?

        6)  Используйте using namespace std; и избавьтесь от надоедливых std:: перед cout и endl

*/