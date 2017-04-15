#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define M 5
#define SIZE 200 * 1024 * 1024


int main()
{
	int N = SIZE / M;
	int * a = (int *)malloc(M * N * sizeof(int));
	int i, j;
	for (i = 0; i < M; ++i)
		for (j = 0; j < N; ++j)
		{
			// Option 1:
			a[i + j * M]++;
		}
	free(a);
	return 0;
}
