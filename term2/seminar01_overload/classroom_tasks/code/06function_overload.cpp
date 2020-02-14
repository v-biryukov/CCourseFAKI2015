#include <cstdio>


void print(int x)
{
	printf("Int: %d\n", x);
}

void print(float x)
{
	printf("Float: %f\n", x);
}

void print(double x)
{
	printf("Double: %lf\n", x);
}

int main()
{
	int a = 15;
	float b = 4.214;

	print(a);
	print(b);
	print(7.3);

}