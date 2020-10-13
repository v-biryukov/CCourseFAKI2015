#include <stdio.h>
#define MAX 100

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int table[MAX][MAX];
	int n, m;

	FILE* fin = fopen("turtle_test_0.txt", "r");
	fscanf(fin, "%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			fscanf(fin, "%d", &table[i][j]);
	flose(fin);

	// Ваш код дальше
}