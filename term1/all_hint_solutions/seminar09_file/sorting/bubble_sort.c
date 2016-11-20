#include <stdio.h>
#include <stdlib.h>

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




int main(int argc, char ** argv)
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

	bubble_sort(A, n);
	
	// Записывае данные и закрываем файлы

	for (int i = 0; i < n; ++i)
		fprintf(fout, "%d ", A[i]);

	fclose(fout);
	free(A);
	return 0;
}
