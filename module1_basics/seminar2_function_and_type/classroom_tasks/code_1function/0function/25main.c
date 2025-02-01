/*
    main тоже является функцией. Но это особая функция. Любая программа на языке C начинаяется с функции main.

    
    Также, вы могли заметить, что функция main возвращает целое число типа int, но почему-то внутри функции main
    мы нигде не писали ключевое слово return.

    На самом деле функция main возвращает так называемый код возврата. По коду возврата операционная система или 
    другая программа, которая запустила нашу программу, могут понять как завершилась наша программа.

    Как правило, если функция main программы возвращает 0, то это означает, что программа завершилась без ошибок.
    Если же функция main программы возвращает не 0, то это обычно означает, что программа завершилась с некоторой ошибкой.
    И по значению кода возврата операционная система может понять какая именно ошибка возникла в нашей программе.


    Если мы дошли до конца функции main, то получается что всё прошло без ошибок и мы должны вернуть число 0.
    Но если вы не написали return 0; в конце функции main, то компилятор добавит эту строку в конец функции main за вас, 
    поэтому писать return 0; в конце функции main необязательно (это относится только к функции main).
*/

#include <stdio.h>


int main()
{
    int a, b;
    scanf("%i%i", &a, &b)

    if (b == 0)
    {
        printf("Error!\n");
        return 1;
    }

    printf("%i\n", a / b);
    return 0; 
}