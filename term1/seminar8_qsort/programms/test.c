#include <stdio.h>

typedef unsigned long long m_int;


m_int fib(m_int n)
{
	if (n <= 1)
		return 1;
	else 
		return fib(n-2) + fib(n-1);
}

m_int fib2(m_int n)
{
	m_int f1 = 1, f2 = 1;
	for (m_int i = 0; i < n; ++i)
	{
		m_int temp = f2;
		f2 = f1 + f2;
		f1 = temp;
	}
	return f1;
}


m_int main()
{

	for (int i = 0; i < 92; ++i)
	{
		printf("fib  of %d = %llu\n", i, fib(i));

		//printf("fib2 of %d = %llu\n", i, fib2(i));
	}

	return 0;
}
