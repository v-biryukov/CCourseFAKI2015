/*
    Читаем строку

    Считать строку из стандартного ввода можно с помощью std::cin:

        std::string s;
        cin >> s;

    Но в этом случае строка считается только до пробела. 


    Чтобы считать строку до символа переноса строки:

        std::string s;
        std::getline(cin, s);


    Чтобы считать строку до какого-то заданного символа. Например, до символа '#':

        std::string s;
        std::getline(cin, s, '#');

*/

#include <iostream>
#include <string>
using std::cout, std::cin, std::endl;


int main()
{
    std::string a;
    std::getline(cin, a);
    cout << a << endl;


    std::string b;
    cin >> b;
    cout << b << endl;
}

/*
    Задача:

        На вход приходит строка содержащая какие-то символы и символ точки '.'.
        Вам нужно считать строку до символа точки и напечатать.

            Вход                Выход

            www.google.com      www

            a.b.c               a

            .hello      

*/  