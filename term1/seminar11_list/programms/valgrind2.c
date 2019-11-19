#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	int n = 3;
	int* array = malloc(n);
	for (int i = 0; i < n; i++)
	{
		array[i] = i * i;
		printf("%d: %d\n", i, array[i]);
	}
	return 0;
}
