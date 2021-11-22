#include <stdio.h>

int square(int a)
{
	return a * a;
}

int add_one(int a)
{
	return a + 1;
}

int mult2(int a)
{
	return 2 * a;
}

int divide2(int a)
{
	return a / 2;
}


void foreach(int* array, int size, int (*f)(int))
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = f(array[i]);
	}
}


void print_array(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n\n");
}


int main()
{

	int numbers[6] = {1, 5, 2, 6, 2, 4};
	int n = 6;
	print_array(numbers, n);

	printf("Square all numbers:\n");
	foreach(numbers, n, square);
	print_array(numbers, n);

	printf("Add 10 to all numbers:\n");
	foreach(numbers, n, add_one);
	print_array(numbers, n);

	printf("Multiply by 2 all numbers:\n");
	foreach(numbers, n, mult2);
	print_array(numbers, n);
}