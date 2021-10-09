#include <stdio.h>
#define MAX 200

int main()
{
	int f[MAX] = {};
	int n;
	scanf("%d", &n);
	f[0] = 1;
	f[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		f[i] = f[i-1] + f[i-2];
	}
	printf("%d\n", f[n]);
}