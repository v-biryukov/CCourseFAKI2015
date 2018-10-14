#include <stdio.h>

#define N 5


// Обратите внимание, что при передаче 2d массива обязательно указывать размер массива
// (Первый размер указывать не обязательно)
void print(int A[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            printf("%6d ", A[i][j]);
        printf("\n");
    }
}


void sum(int S[N][N], int A[N][N], int B[N][N])
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            S[i][j] = A[i][j] + B[i][j];
}



int main()
{

    int A[N][N] = {{  43,  12, 87, -45, -53},
                   {  -5,  34, 31, -98, -74},
                   { -65,  -1, 45, -43,  97},
                   {  54, -63, 12,  54,-102},
                   {  -7,  82,  3,  64,   4}};

    int B[N][N] = {{    8,   49,  -44,  83,  -14},
                   {   -7,   71,   87, -67,  -67},
                   {  -74,  -70,  -18, -49,  -89},
                   { -100,  -41,  -44, -63,  -34},
                   {  -41,  -78,  -84,  74,   72}};

    printf("A:\n");
    print(A);
    printf("B:\n");
    print(B);


    int C[N][N];
    sum(C, A, B);
    printf("A + B:\n");
    print(C);

    // Задание 1) Написать и проверить функцию вычитания двух 2d массивов


    // Задание 2) Написать и проверить функцию умножения массива на число


    // Задание 3) Написать и проверить функцию поэлементного умножения массивов
    //                           Cij = Aij * Bij


    // Задание 4) Написать и проверить функцию математического умножения массивов (строка на столбец)
    //                           Cij = СУММА_по_k(Aik * Bkj)
    /* Правильный результат для математического умножения A*B:
           495   2848   4018  -2585 -11435 
         10262   9789  13148  -3514  -6963 
         -3520 -12209  -4293   2354   5418 
         -1233   3075  -1881  -2835  -6783 
         -7416   2333   4236  -9958  -7551
    */


    
    // Задание 5) Написать и проверить функцию assign - присваивания одного массива к другому
    //            Вам нужно просто присвоить все их элементы


    // Задание 6) Используя решения задач 4 и 5, напишите функцию square, которая будет возводить матрицу в квадрат


}