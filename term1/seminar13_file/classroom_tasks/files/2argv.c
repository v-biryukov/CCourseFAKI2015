#include <stdio.h>


int main(int argc, char** argv)
{
	printf("Number of arguments = %d\n", argc);

	for (int i = 0; i < argc; ++i)
	{
		printf("Argument #%d = %s\n", i, argv[i]);
	}

	// Попробуйте вызвать эту программу с несколькими аргументами
	// Например, так:
	// ./a.out hello world
	// Что напечатает программа в этих случаях?
}