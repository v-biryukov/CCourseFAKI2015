#include <stdio.h>
#include "pq.h"


int cmp(const void * a, const void * b)
{	
	int na = *(int *)a;
	int nb = *(int *)b;

	return na - nb;
}


int main()
{
	int N = 10;
	int i;
	PQ A = pq_create(4, cmp);
	for (i = 0; i < 10; ++i)
	{
		int n;
		scanf("%d", &n);
		pq_insert(A, &n);
	}

	for (i = 0; i < 10; ++i)
	{
		int n;
		pq_delete_min(A, &n);
		printf("%d ", n);

	}
	printf("\n");

	pq_destroy(A);

	return 0;
}
