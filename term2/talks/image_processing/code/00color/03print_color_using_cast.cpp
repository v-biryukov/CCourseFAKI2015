/*
    Печать компонент цвета.

    Для печати компонент цвета можно привести объекты типа unsigned char к типу int.
*/

#include <iostream>
#include <array>

int main()
{
    std::array<unsigned char, 3> a {40, 80, 120};

    std::cout << static_cast<int>(a[0]) << " "
              << static_cast<int>(a[1]) << " "
              << static_cast<int>(a[2]) << std::endl;
}