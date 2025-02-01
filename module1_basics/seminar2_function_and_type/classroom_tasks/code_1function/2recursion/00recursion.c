/*
    Рекурсия

    В языке C (как и во многих других языках) функции могут вызывать себя.
    Функции, которые вызывают сам себя, называются рекурсивными.

    
    Рассмотрим следующую рекурсивную функцию:

        void counter(int n)
        {
            printf("%i\n", n);
            counter(n - 1);
        }

    Функция counter принимает одно целое число, печатает это число и 
    вызывает функцию counter, но только передав ей на единицу меньшее число.


    Допустим мы вызвали функцию counter, передав её число 10. Что произойдёт в этом случае?

        counter(10): Печатаем число 10 и вызываем функцию counter, передав ей число 9.
        counter(9):  Печатаем число 9  и вызываем функцию counter, передав ей число 8.
        counter(8):  Печатаем число 8  и вызываем функцию counter, передав ей число 7.
        и так далее

    Этот процесс не остановится на нуле и будет бесконечно печатать всё уменьшающиеся на 1 числа.
    (на самом деле не совсем бесконечный так как каждый рекурсивный вызов функции требует памяти,
     и рано или поздно вся память закончится и программа завершится с ошибкой)

*/


#include <stdio.h>


void counter(int n)
{
    printf("%i\n", n);
    counter(n - 1);
}

int main()
{
    counter(10);
}



/*
    Задачи:

        1)  Скомпилируйте программу и запустите.
            Убедитесь, что программа бесконечно печатает уменьшающиеся на 1 числа.
            Чтобы выйти из программы можно использовать  Ctrl-C
    

        2)  Измените функцию counter так чтобы все числа печатались через пробел.

        3)  Измените функцию counter так чтобы печать чисел останавливалась на единице.
*/