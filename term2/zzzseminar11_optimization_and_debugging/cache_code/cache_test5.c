#include <stdio.h>
#include <stdlib.h>
#define N 1000
#define B 50

void mat_mult_ijk(double a[N][N], double b[N][N], double c[N][N])
{
	int i, j, k;
	double sum;
	for (i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			sum = 0.0;
			for (k=0; k<N; k++)
				sum += a[i][k] * b[k][j];
			c[i][j] = sum;
		}
	}
}

void mat_mult_kij(double a[N][N], double b[N][N], double c[N][N])
{
	int i, j, k;
	double r;
	for (i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			c[i][j] = 0;
		}
	}

	for (k=0; k<N; k++)
	{
		for(i=0; i<N; i++)
		{
			r = a[i][k];
			for (j=0; j<N; j++)
				c[i][j] += r * b[k][j];
		}
	}
}


void mat_mult_block(double *a, double *b, double *c)
{
	int i, j, k, i1, j1, k1;
	double sum;
	for (i=0; i<N; i+=B)
	{
		for(j=0; j<N; j+=B)
		{
			for(k=0; k<N; k+=B)
			{
				for (i1=i; i1<i+B; i1++)
					for (j1=j; j1<j+B; j1++)
					{
						sum = 0.0;
						for (k1=k; k1<k+B; k1++)
							sum += a[i1*N + k1] * b[k1*N + j1];
						c[i1*N+j1] = sum;
					}
			}
		}
	}
}




// Протестируйте разные функции умножения матриц
// С разными N и B(для mat_mult_block)

int main()
{
	double* a = (double*)malloc(N * N * sizeof(double));
	double* b = (double*)malloc(N * N * sizeof(double));
	double* c = (double*)malloc(N * N * sizeof(double));
	mat_mult_block(a, b c);
	//mat_mult_block(a, b, c);
	/*
	int i, j;
	for (i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	*/
	free(a);
	free(b);
	free(c);
	return 0;
}