#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


void count_sort(int arr[], int n, int range)
{
    int* output = malloc(n * sizeof(int));
    int* count = malloc(range * sizeof(int));
    memset(output, 0, n * sizeof(int));
    memset(count, 0, range * sizeof(int));
 
    int i;
    for(i = 0; i < n; ++i)
        ++count[arr[i]];
 
    for (i = 1; i < range; ++i)
    {
        count[i] += count[i-1];
    }
 
    for (i = 0; i < n; ++i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }
 
    for (i = 0; i < n; ++i)
        arr[i] = output[i];

    free(output);
    free(count);
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
	int* A = (int*)malloc(n * sizeof(int));
	for ( i = 0; i < n; ++i )
	{
		fscanf(fin, "%d", &A[i]);
	}
	fclose(fin);

    int range = A[0];
    for (int i = 0; i < n; ++i)
        if (A[i] > range)
            range = A[i];
    range += 1;
	// Сортируем
	count_sort(A, n, range);

	// Записываем данные и закрываем файлы
	for (int i = 0; i < n; ++i)
		fprintf(fout, "%d ", A[i]);

	fclose(fout);
	free(A);
	return 0;
}
