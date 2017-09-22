#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1001


int calc_lcs(char X[MAX_SIZE], char Y[MAX_SIZE])
{
	int C[MAX_SIZE][MAX_SIZE];
	int i, j;
	int size_x = strlen(X) + 1;
	int size_y = strlen(Y) + 1;
	for (i = 0; i < size_x; ++i)
		for (j = 0; j < size_y; ++j)
			C[i][j] = 0;


	for (i = 1; i < size_x; ++i)
		for (j = 1; j < size_y; ++j)
		{
			if (X[i-1] == Y[j-1])
				C[i][j] = C[i-1][j-1] + 1;
			else if (C[i][j-1] > C[i-1][j])
				C[i][j] = C[i][j-1];
			else
				C[i][j] = C[i-1][j];
		}

	for (i = 0; i < size_x; ++i)
	{
		for (j = 0; j < size_y; ++j)
			printf("%2d ", C[i][j]);
		printf("\n");
	}

	return C[size_x-1][size_y-1];
}

int main()
{
	char s1[MAX_SIZE];
	char s2[MAX_SIZE];
	scanf("%s", s1);
	scanf("%s", s2);

	printf("%d\n", calc_lcs(s1, s2));



	return 0;
}