#include <stdio.h>

void bubble_sort(int * A, int hi)
{

	for (int i = 0; i < hi; ++i)
	{
		for (int j = 0; j < hi - 1; ++j)
		{
			if (A[j] > A[j+1])
			{

				int temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
}




int main()
{
	int A[10] = {4, 6, 2, 62, 63, 43, 1, 11, -5, 98};

	bubble_sort(A, 10);
	
	for (int i = 0; i < 10; ++i)
		printf("%d ", A[i]);
	printf("\n");	


	return 0;
}
