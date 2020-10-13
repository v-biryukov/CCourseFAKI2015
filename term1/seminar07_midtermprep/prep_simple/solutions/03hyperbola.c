#include <stdio.h>

int main()
{
	double x, y;
	scanf("%lf%lf", &x, &y);
	if (x > 0 && x * y > 1.0)
		printf("YES\n");
	else
		printf("NO\n");
}