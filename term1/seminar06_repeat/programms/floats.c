#include <stdio.h>

int main()
{
	// Test float
	float a = 52200.0;
	
	printf("float а = %f\n", a);
	printf("Size of float a in bytes = %ld\n\n", sizeof(a));

	// Test double
	double b = 52200.0;
	
	printf("double b = %f\n", b);
	printf("Size of double b in bytes = %ld\n\n", sizeof(b));


	// Float precision
	float n = 1000000.0;
	float m = 5.0e-3;
	float l = n+m;
	printf("float m = %f\n", m);
	printf("float l - n = %f\n\n", (l-n));

	// Double precision
	double nd = 1000000.0;
	double md = 5.0e-3;
	double ld = nd+md;
	printf("double md = %f\n", md);
	printf("double ld - nd = %f\n", (ld-nd));

	return 0;
}
