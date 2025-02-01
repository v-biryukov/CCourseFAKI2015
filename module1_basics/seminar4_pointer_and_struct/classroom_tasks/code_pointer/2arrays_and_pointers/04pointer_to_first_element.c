/*
    Указатель на первый элемент

    Предположим, что указатель хранит адрес первого элемента массива:


        int a[6] = {10, 20, 30, 40, 50, 60};

        int* p = &a[0];


    Вот как эта ситуация выглядит в памяти:


   |--------a[0]-------|--------a[1]-------|--------a[2]-------|--------a[3]-------|--------a[4]-------|--------a[5]-------|
═══╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════╤════
   │ 00 │ 00 │ 00 │ 10 │ 00 │ 00 │ 00 │ 20 │ 00 │ 00 │ 00 │ 30 │ 00 │ 00 │ 00 │ 40 │ 00 │ 00 │ 00 │ 50 │ 00 │ 00 │ 00 │ 60 │    │
═══╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════╧════
     ▲                                              
     |                                              
     p                                 

    
    Теперь, если мы напишем  p[i], то это будет равно *(p + i), то есть то же самое, что и a[i].
    Несмотря на то, что p и a это разные вещи: p это указатель, а a это массив.

    Таким образом, если указатель хранит адрес первого элемента массива, то можно использовать этот
    указатель, как-будто это сам массив.
*/

#include <stdio.h>

int main()
{
    int a[6] = {10, 20, 30, 40, 50, 60};
    int* p = &a[0];


    // a и p это переменные разных типов, они имеют разный размер:
    printf("Size of p = %zu\n", sizeof(p));
    printf("Size of a = %zu\n", sizeof(a));


    // Тем не менее, с указателем на первый элемент можно работать так, как будто это сам массив:
    a[1] += 1;
    p[1] += 1;

    for (int i = 0; i < 6; ++i)
        printf("%i ", a[i]);
    printf("\n");

    for (int i = 0; i < 6; ++i)
        printf("%i ", p[i]);
    printf("\n");
}
