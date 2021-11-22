#include <stdio.h>


int partition(int * A, int lo, int hi)
{
	int pivot = A[hi];
	int i = lo;
	for (int j = lo; j < hi; ++j)
	{
		if (A[j] <= pivot)
		{
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
		}
	}
	int temp = A[i];
	A[i] = A[hi];
	A[hi] = temp;
	return i;
}



void qsort(int * A, int lo, int hi)
{
	if (lo < hi)
	{
		int p = partition(A, lo, hi);
		qsort(A, lo, p-1);
		qsort(A, p+1, hi);
	}

}


int main()
{

	int A[10] = {5, 3, 6, 2, 63, 34, 34, 73, 11, 1};
	qsort(A, 0, 9);
	
	for (int i = 0; i < 10; ++i)
		printf("%d ", A[i]);
	printf("\n");


}
