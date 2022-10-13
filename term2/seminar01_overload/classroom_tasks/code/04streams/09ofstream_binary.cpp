/*
    Бинарная печать

    Для бинарной печати нужно открыть файл в режиме std::ios::binary.
    Для печати используется метод write класса std::ofstream.
    На вход этому методу нужно передать указатель (типа char*) и количество байт для записи.

    В этом примере используется reinterpret_cast для приведения типа int* к типа char*.
*/


#include <fstream>

int main()
{
    std::ofstream out("hello.bin", std::ios::binary);

    int a = 0x11221344;
    out.write(reinterpret_cast<char*>(&a), 4);
}