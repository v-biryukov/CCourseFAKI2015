#include <stdio.h>
#include <math.h>


double is_equal(double a, double b, double eps)
{
	return fabs(a - b) < eps;
}

int main()
{
	double x, y;
	scanf("%lf%lf", &x, &y);
	if (is_equal(x, y, 1e-6))
		printf("Equal\n");
	else
		printf("Not Equal\n");
}