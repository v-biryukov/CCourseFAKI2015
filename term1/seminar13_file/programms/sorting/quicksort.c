#include <stdio.h>
#include <stdlib.h>


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



void quicksort(int * A, int lo, int hi)
{
	if (lo < hi)
	{
		int p = partition(A, lo, hi);
		quicksort(A, lo, p-1);
		quicksort(A, p+1, hi);
	}

}


int main()
{
	// Открываем файлы и считываем данные
	FILE *fin, *fout;
	fin = fopen("numbers.txt", "r");
	fout = fopen("output.txt", "w");
	if(fin == NULL || fout == NULL)
	{
		printf("Error!");
		return 1;
	}

	int n, i;
	fscanf(fin, "%d", &n);
	int * A = (int *)malloc(n * sizeof(int));
	for ( i = 0; i < n; ++i )
	{
		fscanf(fin, "%d", &A[i]);
	}
	fclose(fin);

	// Сортируем
	quicksort(A, 0, n-1);

	// Записывае данные и закрываем файлы
	for (int i = 0; i < n; ++i)
		fprintf(fout, "%d ", A[i]);

	fclose(fout);
	free(A);

	return 0;

}
