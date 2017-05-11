#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define M 1*1024*1024
#define N 100


int sum_array_rows(int a[M][N])
{
	int i, j, sum = 0;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			sum += sin(cos(sin(a[i][j])));
	return sum;
}

int main()
{
	int * a = (int *)malloc(M * N * sizeof(int));
	int s = sum_array_rows(a);
	//printf("%d\n", s);
	free(a);
	return 0;
}