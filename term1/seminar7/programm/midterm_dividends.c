
#include <stdio.h>

int main()
{
	long long int a, b, N, d;
	scanf("%lld%lld%lld%lld", &a, &b, &N, &d);
	// Находим первый элемент
	long long int first = b - b % d;
	long long int i;
	// Пытаемся напечатать N элементов
	for (i = 0; i < N; ++i)
	{
		// Находим следующий элемент
		long long int n = first - i*d;
		// Если он меньше, чем 1-е число, выходим из цикла
		if (n < a)
			break;
		// Печатаем число
		printf("%lld ", n);
	}
	printf("\n");
	return 0;
}
