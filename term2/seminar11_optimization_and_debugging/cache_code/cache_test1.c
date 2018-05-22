#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define M 10 * 1024
#define N 10 * 1024


int main()
{
	int a[M][N];
	int i, j;
    // Протестируйте быстродействие поменяв местами циклы по i и по j
	for (i = 0; i < M; ++i)
		for (j = 0; j < N; ++j)
		{
			a[i][j]++;
		}
	free(a);
	return 0;
}