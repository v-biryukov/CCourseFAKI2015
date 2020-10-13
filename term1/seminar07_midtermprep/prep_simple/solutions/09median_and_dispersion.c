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
	float median = sum / n;

	float dispersion = 0;

	for (int i = 0; i < n; i++)
		dispersion += (array[i] - median) * (array[i] - median);

	dispersion /= n;

	printf("Median = %g, Dispersion = %g\n", median, dispersion);
}