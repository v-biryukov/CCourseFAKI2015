#include <stdio.h>
#define MAX 1000

int main()
{
	int n;
	float array[MAX];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%f", &array[i]);
	
	float sum = 0;
	for (int i = 0; i < n; i++)
		sum += array[i];

	for (int i = 0; i < n; i++)
		array[i] = array[i] / sum;

	for (int i = 0; i < n; i++)
		printf("%g ", array[i]);
	printf("\n");
}