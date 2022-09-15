/*
    Методы класса std::string:


    insert - добавляет символы в строку (возможно несколько символов)
    erase  - удаляет символы из строки (возможно несколько символов)
    
    substr(pos, len) - возвращает подстроку, задаваемую числами pos и len
                       pos - это индекс начала подстроки. len - длина подстроки.
                       возвращаемый тип - std::string

    find(str, pos)   - ищет str в нашей строке, начиная с индекса pos. возвращает индекс первого совпадения.
                       если ничего не нашёл, то возвращает string::npos.


    starts_with(str) - проверяет, начинается ли строка со строки str
    ends_with(str)   - проверяет, кончается ли строка на строку str
*/

#include <iostream>
#include <string>
using std::cout, std::endl;


int main()
{
    std::string s;
}

/*
    Задачи:

        1)  Напишите функцию, которая принимает на вход строку и если строка начинается на www.
            и кончается на .com, то эта функция должна вернуть true, иначе false.

            Вход                       Выход

            www.google.com                 true
            www.wikipedia.org              false
            www.help.facebook.com          true
            hello.com                      false
            abc                            false


        2)  На вход приходит строка. Вам нужно узнать сколько раз и в каких позициях в строке содержится строка "cat".

            Вход                       Выход

            cat and dog and cat        2: 0, 16
            look, cats were here       1: 6
            catcher catching catfish   3: 0, 8, 17
            catcatcatcatcatcat         6: 0, 3, 6, 9, 12, 15
            a                          0:

        3)  Напишите функцию, которая принимает на вход строку, которая может содержать разные символы.
            Но среди этих символов содержится ровно 2 точки.
            Вам нужно вернуть подстроку между этими двумя символами.

            Вход                       Выход

            www.google.com             google
            a.b.c                      b
            cat.dog.                   dog
            .hello.                    hello
            ..

*/