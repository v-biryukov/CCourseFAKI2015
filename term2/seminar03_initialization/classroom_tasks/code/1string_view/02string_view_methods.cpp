/*
    Методы класса string_view
    
    У std::string_view есть все аналоги константных методов класса std::string кроме c_str. 

        find, substr, starts_with, ends_with, operator> и другие сравенение
    
    кроме этого у string_view есть два дополнительных метода:

        remove_prefix(n) - передвигает начала "окошка" на n символов вперёд
        remove_suffix(n) - передвигает конец "окошка" на n символов назад

*/




#include <iostream>
#include <string>
#include <string_view>

using std::cout, std::cin, std::endl;


int main()
{
    std::string a = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed imperdiet dolor eu velit gravida iaculis.";

    std::string_view b = a;
    cout << b << endl;
}


/*
    Задачи:


        1)  Напишите функцию, которая принимает на вход строку по string_view, которая может содержать разные символы.
            Но среди этих символов содержится ровно 2 точки.
            Вам нужно вернуть подстроку между этими двумя символами.

            Вход                       Выход

            www.google.com             google
            a.b.c                      b
            cat.dog.                   dog
            .hello.                    hello
            ..


        2)  На вход приходит число, ваша задача заключается в том, чтобы написать половину "ёлочки" из этого слова.

            Вход            Выход

            Hello           H
                            He
                            Hel
                            Hell
                            Hello 

*/