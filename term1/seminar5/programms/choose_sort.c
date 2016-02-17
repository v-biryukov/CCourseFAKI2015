#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


int main()
{
	
	int n;
	scanf("%d", &n);
	int numbers[100];
	for (int i = 0; i < n; ++i)
		scanf("%d", &numbers[i]);
	
	for (int i = 0; i < n; ++i)
	{
		int min_index = i;
		for (int j = i+1; j < n; ++j)
			if (numbers[j] < numbers[min_index])
				min_index = j;
				
		int temp = numbers[i];
		numbers[i] = numbers[min_index];
		numbers[min_index] = temp;
	}
	
	for (int i = 0; i < n; ++i)
		printf("%d ", numbers[i]);
	printf("\n");
	
	return 0;
}

