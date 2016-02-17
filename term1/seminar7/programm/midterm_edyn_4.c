#include <stdio.h>

int main()
{
	int n, k;
	long double x;
	scanf("%d%d", &n, &k);
	// Будем использовать тип long double
	long double c = 1.0;
	// Цикл с использованием этого типа
	for (x = 0.0; x < k - 0.5; x += 1.0)
	{
		// Если бы мы использовали int, то были бы ошибки округления
		// Если бы мы вычисляли сразу n! и k!, то число бы не влезло даже в long double (возникли бы ошибки округления)
		c *= (n-x)/(k-x);
	}
	
	printf("%lld\n", (unsigned long long int)(c+0.5));
	return 0;
}
