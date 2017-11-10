#include <stdio.h>

int add7(int a)
{
	a += 7;
	return a;
}

int main()
{
	int x = 17, y = 25;
	x = add7(x);
	printf("%d\n", x + y);
}