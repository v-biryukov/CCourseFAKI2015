#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846

double func(double x)
{
	return pow(fabs(sin(x * M_PI / 180)), 3.5);
}

int main()
{
	double a;
	scanf("%lf", &a);
	printf("%lf\n", func(a));
}