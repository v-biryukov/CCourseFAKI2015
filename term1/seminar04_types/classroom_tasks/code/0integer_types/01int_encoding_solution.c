#include <stdio.h>

int main()
{
    int a = 2147483647;

    printf("%i\n", a);
    printf("%i\n", a + 1);
    printf("%i\n", a + 2);
}

/*
    Решение:
        
        Эта программа является ошибочной!

        Дело в том, что отрицательные числа могут кодироваться по разному на разных вычислительных системах.
        И даже если на вашем компьютере данная программа напечатает:

            2147483647
            -2147483648
            -2147483647

        То это только потому что на вашем компьютере используется дополнительный код для представления 
        отрицательных чисел. А на другой вычислительной системе программа может повести себя по-другому.

        
        Такой результат выполнения программы называется Неопределённым Поведением или по-английски
        Undefined Behavior или просто UB
*/