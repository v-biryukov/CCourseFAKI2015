#include <stdio.h>


int main()
{
    char str[201];
    scanf("%200[^\n]", str);


}



/*
    Задачи:

        1)  Напишите функцию count_words, которая должна принимать на вход строку и возвращать  
            количество слов в этой строке. Под словом тут понимается последовательность непробельных символов,
            ограниченная с двух сторон пробельными символами или границами строки.

                вход                        выход

                The Fox Jumps Over The Dog      6
                cats and dogs                   3
                cats   and     dogs             3
                cat                             1
                   cat                          1



        2)  Напишите функцию, которая будет сортировать символы строки по их коду ASCII.
            Можно воспользоваться простой сортировкой вроде сортировки выбором.

                вход                                выход

                MIPT                                IMPT
                Majestic12                          12Maceijst
                abcABC                              ABCabc
                The Fox Jumps Over The Dog               DFJOTTeeeghhmooprsuvx


        3*) На вход передаётся целое положительное число n < 10^10000. 
            Нужно напечатать это число, умноженное на 3.

                вход                                        выход
                1234567890987654321234567890987654321       3703703672962962963703703672962962963


*/