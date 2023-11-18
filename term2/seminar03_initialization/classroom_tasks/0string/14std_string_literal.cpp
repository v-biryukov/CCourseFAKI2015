/*
    Литералы типа std::string.

    Как известно строковые литералы имеют тип массива элементов типа char.
    Например, строка "Cat Dog Mouse" имеет тип const char[14].

    Чтобы преобразовать эту строку в тип std::string нужно использовать конструктор:

        std::string("Cat Dog Mouse")

    Но то же самое можно записать более кратко, используя литералы std::string:

        "Cat Dog Mouse"s

    Эти литералы находятся в стандартной библиотеке string в пространстве имён std::string_literals.
    Чтобы их подключить нужно использовать:

        using namespace std::string_literals;
*/

#include <iostream>
#include <string>
#include <cstring>
using std::cout, std::cin, std::endl;
using namespace std::string_literals;


void func(std::string s)
{
    std::cout << s << std::endl;
}

int main()
{
    func(std::string("Cat Dog Mouse"));
    func("Cat Dog Mouse"s);


    func("Cat Dog Mouse");  // Конечно, так то же будет работать. const char* автоматически преобразуется в std::string.
                            // Но в дальнейшем будут ситуации, где без явного преобразования const char* в std::string
                            // не обойтись.
}