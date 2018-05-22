#include <stdlib.h>
#include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	if ( num < 0 )
	{
		printf("Error: number should be positive\n");
		exit(1);
	}

	int factorial;
	for (int i = 1; i <= num; i++)
		factorial = factorial * i;

	printf("%d! = %d\n", num, factorial);

	return 0;
}