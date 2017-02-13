#include <stdio.h>
#include <stdlib.h>
#include "pq.h"


int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
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
	PQ queue = pq_create(4, cmpfunc);
	for (i = 0; i < n; ++i)
	{
		pq_insert(queue, &A[i]);
	}

	// Записывае данные и закрываем файлы
	for (i = 0; i < n; ++i)
	{
		int num;
		pq_delete_min(queue, &num);
		fprintf(fout, "%d ", num);
	}		

	fclose(fout);
	free(A);

	return 0;

}
