#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Протестируйте работу программы с различными значениями N
// Постройте график время работы от N
#define N 10 * 1024

int main()
{
	int a[N][N];
	int i, j, k;
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
		{
            for (k = 0; k < 10000; ++k)
			     a[i][j]++;
		}
	free(a);
	return 0;
}