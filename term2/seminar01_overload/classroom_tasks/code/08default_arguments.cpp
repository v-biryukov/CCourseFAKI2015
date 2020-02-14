#include <cstdio>


void print_square(char c, int width = 10, int height = 5)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			printf("%c", c);
		}
		printf("\n");
	}
}

int main()
{
	print_square('+', 30, 50);
	print_square('#', 20);
	print_square('O');
	
	/*
	Задание:
	1) Написать функцию:
		void print(char str[], bool is_capitalized = false)
		Которая будет просто печатать строку str, если is_capitalized = false,
		а если is_capitalized = true, то будет печатать всю строку в верхнем регистре

	*/
}