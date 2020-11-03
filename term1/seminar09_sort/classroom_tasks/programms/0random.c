#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Random number = %d (from 0 to %d)\n", rand(), RAND_MAX);

	int a = rand() % 10;
	printf("Random number (from 0 to 9) = %d\n", a);

	float x = (float)rand() / RAND_MAX;
	printf("Random float number (from 0 to 1) = %f\n", x);


	// Можно генерировать числа большие RAND_MAX:
	int c = rand() * (RAND_MAX + 1) + rand();
	printf("Random number = %d (from 0 to %llu)\n", c, RAND_MAX * RAND_MAX);
}