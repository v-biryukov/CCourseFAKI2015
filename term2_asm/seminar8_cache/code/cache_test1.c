#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define M 10 * 1024
#define N 10 * 1024


int main()
{
	int * a = (int *)malloc(M * N * sizeof(int));
	int i, j;
	for (i = 0; i < M; ++i)
		for (j = 0; j < N; ++j)
		{
			// Option 1:
			a[i + j * M]++;
			// Option 2;
			// a[j + i * N]++;
		}
	free(a);
	return 0;
}