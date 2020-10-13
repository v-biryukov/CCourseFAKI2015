#include <stdio.h>

int main()
{
	float x, y, R;
	scanf("%f%f%f", &x, &y, &R);
	printf(x*x + y*y < R*R ? "YES\n" : "NO\n");
}