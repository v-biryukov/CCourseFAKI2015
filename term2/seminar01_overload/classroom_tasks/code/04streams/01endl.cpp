/*
    std::endl

    Для переноса на новую строку можно использовать std::endl вместо "\n".
    Однако std::endl работает медленнее, чем "\n" так как std::endl не только переводит 
    на новую строку, но ещё и сбрасывает буфера вывода (т. е. делает flush).
*/


#include <iostream>

int main()
{
    std::cout << "Hello!" << std::endl;

    int a = 123;
    std::cout << a << std::endl;

    float b = 1.5;
    std::cout << a << std::endl;
}