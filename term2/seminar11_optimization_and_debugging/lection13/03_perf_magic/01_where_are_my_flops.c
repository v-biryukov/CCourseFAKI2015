#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000*1000*1000

int main()
{
    double* a = (double*)malloc(SIZE*sizeof(double));

    double result = 1;
    long i;
    for(i = 0; i < SIZE; i++) {
        result = result * a[i];
    }

    printf("Res = %lf\n", result);
    free(a);
    return 0;
}
