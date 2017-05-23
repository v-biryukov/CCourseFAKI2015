#include <stdio.h>
#define N 10000


int main()
{
	int A[N], B[2*N], sum=0;
	for (int i = 0; i < N; ++i) {
	    sum += A[i] + B[2*i];
	}
	printf("%d\n", sum);
	return 0;
}