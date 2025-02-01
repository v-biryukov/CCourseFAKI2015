#include <stdio.h>

int main()
{
    char str[200];
    scanf("%s", str);
}

/*
    Задачи:
    
        1)  Считайте число n и строку str и напечатайте строку n раз через пробел. 
            Для считывания используйте scanf со спецификатором %s.


        2)  Считайте строку и напечатайте её удвоив каждый символ.

                вход        выход

                Hello       HHeelllloo
                MIPT        MMIIPPTT
                a           aa


        3)  На вход подаётся строка. Усечь строку до первого символа точка(.) 
            Можно использовать только один вызов функции printf.

                вход                выход

                judge.mipt.ru       judge
                A.B.C.              A
                .com                
                cat                 cat      



        4)  На вход передаётся целое положительное число n < 10^1000. 
            Нужно найти сумму цифр этого числа и напечатать. 
            Подсказка: Считайте это число как строку.

                вход                                    выход
                
                0                                       0
                5                                       5 
                97                                      16
                1234567890987654321234567890987654321   179
                1000000000000000000000000000000000001   2
*/