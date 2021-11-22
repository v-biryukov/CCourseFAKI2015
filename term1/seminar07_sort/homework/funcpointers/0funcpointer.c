#include <stdio.h>

void print(int a) 
{ 
    printf("%d\n", a); 
} 

void sayntimes(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Hello ");
	}
	printf("\n");
}

void square(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < n; i++)
			printf("*");
		printf("\n");
	}
}

int main()
{
	// Создадим указатель на функцию
	// Вместо названия функции - (*p)
	// В дальнейшем p можно пользоваться как будто это функция print
	void (*p)(int n) = print;
	p(4);

	p = sayntimes;
	p(4);

	p = square;
	p(4);

	// Создадим массив из функций
	void (*array[3])(int n) = {print, sayntimes, square};
	for (int i = 0; i < 3; i++)
		array[i](10);
}