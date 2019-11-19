#include <stdlib.h>

int main(void)
{
	int n = 10;
	int* array = malloc(n * sizeof(int));
	for (int i = 0; i <= n; i++)
		array[i] = 0; 
	return 0;
}
