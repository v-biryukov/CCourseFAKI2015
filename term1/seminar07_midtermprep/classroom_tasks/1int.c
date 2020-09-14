#include <stdio.h>

/*
    Степени 2:
    2^8 = 256     2^10 = 1024    2^16 = 65536   2^32 ~ 4 миллиарда    2^64 ~ 1.8*10^19
    2^32 = 4294967296             |    2^31 = 2147483648
    2^64 = 18446744073709551616   |    2^63 = 9223372036854775808

    |||||||||||||||||||||||     Целочисленные типы данных:   |||||||||||||||||||||||||||||||||||
    ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
                           Размер   Размер    Значения                          Спецификатор
    Тип                    (байт)   (бит)     которые может переменная типа     для printf/scanf
           
    long long              8        64        от -2^63 до 2^63-1                %lld  
    long                   4        32        от -2^31 до 2^31-1                %ld                                                                    
    int                    4        32        от -2^31 до 2^31-1                %d                                                                     
    short                  2        16        от -32768 до 32767                %hd   
    char                   1        8         от -128 до 127                    %hhd  

    unsigned long long     8        64        от 0 до 2^64-1                    %llu  
    unsigned long          4        32        от 0 до 2^32-1                    %lu                                                                    
    unsigned int           4        32        от 0 до 2^32-1                    %u                                                                     
    unsigned short         2        16        от 0 до 65535                     %hu   
    unsigned char          1        8         от 0 до 255                       %hhu  
    
    Размеры типов могут немного различаться на разных системах!
    Например, на некоторых системах тип long может иметь размер 8 байт, а не 4 байта
*/


int main()
{
    // Создадим переменную типа unsigned short:
    unsigned short a;
    // Она может хранить числа от 0 до 65535     (т. к. 2^16 = 65536)
    // Число 65535 переменная хранить может:
    a = 65535;
    printf("%hu\n", a);
    // Попробуем увеличить значение на 1. Что напечатает следующий printf?
    a = a + 1;
    printf("%hu\n", a);

    // Попробуем отрицательные числа. Что напечатает следующий printf?
    a = -10;
    printf("%hu\n", a);

    // Попробуем сравнивать с числами вне диапазона. Что и почему напечатает следующий код?
    a = 5;
    if (a > -1)
        printf("YES\n");
    else
        printf("NO\n");

    // Сколько раз напечатает слово Hello следующий участок кода?
    for (a = 10; a >= 0; a--)
        printf("Hello");
    // Задание 1) Исправьте этот цикл, чтобы он печатал Hello 10 раз


    // Задание 2) Считайте 2 числа типа unsigned int и напечатайте остаток деления первого числа на второе





    // Задание 3) Считайте 2 числа и напечатайте их сумму
    // Числа могут быть очень большими. Используйте тип unsigned long long
    // ||||| Ваш код: ||||||||||||||||||||||||||||||||||||||||||||||||||||




    // |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    // Проверьте ваш код:             2 2                                ->  4
    //                                5834643475583443 6455327317354437  ->  12289970792937880
    //                                18446744073709551615 1             ->  0
    //                                0 -10                              ->  18446744073709551606

}