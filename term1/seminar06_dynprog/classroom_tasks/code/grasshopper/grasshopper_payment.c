#include <stdio.h>
#include <stdlib.h>
#define MAX 200



int min(int a, int b)
{
	return a < b ? a : b;
}
int min3(int a, int b, int c)
{
	return min(min(a, b), c);
}


int main()
{
	FILE* fin = fopen("grasshopper_test_0.txt", "r");
	int n;
	fscanf(fin, "%d", &n);
	int payments[MAX];
	for (int i = 0; i <= n; i++)
		fscanf(fin, "%d", &payments[i]);
	fclose(fin);

	// Ваш код дальше
}