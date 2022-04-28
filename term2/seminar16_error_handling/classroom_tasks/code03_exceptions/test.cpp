#include <iostream>

[[nodiscard]] int foo(int x, int y)
{
    int z = (x - x%y) / y;
    return z;
}

int main()
{
    foo(5, 1);
    std::cout << foo(117, 20) << std::endl;
    std::cout << foo(10,  20) << std::endl; // <-- contract violation #1
    std::cout << foo(100, -5) << std::endl; // <-- contract violation #2

    return 0;
}