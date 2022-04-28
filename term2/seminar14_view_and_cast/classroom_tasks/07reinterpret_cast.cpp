#include <iostream>

/*
    reinterpret_cast используется для:
        1) кастования указателя одного типа к указателю другого типа.
        2) кастования указателя к целому числу соответствующего размера (или наоборот)
*/

int main()
{
    int a = 7627075;

    // Не сработает в C++, сработает в C
    // char* p = &a;

    // static_cast не сработает:
    // char* p = static_cast<char*>(&a);

    // C-style cast сработает, но лучше это не использовать
    // char* p = (char)(&a);

    // Лучше использовать reinterpret_cast:
    char* p = reinterpret_cast<char*>(&a);

    for (int i = 0; i < sizeof(int); ++i)
        std::cout << p[i];
    std::cout << "\n";
}  


/*
    1) Проверьте можно ли скастовать указатель типа char* к следующим типам:
        a) void*
        b) int
        c) long long
        d) unsigned long long
    Используя reinterpret_cast


    2) Так как static_cast можно использовать для конвертации указателя к указателю типа void*
       то можно ли использовать два static_cast, чтобы привести указатель одного типа к другому?
       То есть сначала int* привести к void*, а потом void* привести к char*

*/