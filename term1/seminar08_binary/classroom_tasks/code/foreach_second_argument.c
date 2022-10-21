#include <stdio.h>

int power(int a, int b)
{
	int result = 1;
	for (int i = 0; i < b; ++i)
		result *= a;
	return result;
}

int add(int a, int b)
{
	return a + b;
}

int mult(int a, int b)
{
	return b * a;
}

int divide(int a, int b)
{
	return a / b;
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

	printf("Cube all numbers:\n");
	foreach(numbers, n, power, 3);
	print_array(numbers, n);

	printf("Add 10 to all numbers:\n");
	foreach(numbers, n, add, 10);
	print_array(numbers, n);

	printf("Multiply by 2 all numbers:\n");
	foreach(numbers, n, mult, 2);
	print_array(numbers, n);

	printf("Divide by 6 all numbers:\n");
	foreach(numbers, n, divide, 6);
	print_array(numbers, n);
}