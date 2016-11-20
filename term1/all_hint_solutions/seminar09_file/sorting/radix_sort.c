#include <stdio.h>
#include <stdlib.h>

int findLargestNum(int * array, int size){

	int i;
	int largestNum = -1;

	for(i = 0; i < size; i++){
		if(array[i] > largestNum)
			largestNum = array[i];
	}

	return largestNum;
}

// Radix Sort
void radix_sort(int * array, int size){

	//printf("\n\nRunning Radix Sort on Unsorted List!\n\n");

	// Base 10 is used
	int i;
	int * semiSorted = (int *)malloc(size * sizeof(int));
	//int semiSorted[size];
	int significantDigit = 1;
	int largestNum = findLargestNum(array, size);

	// Loop until we reach the largest significant digit
	while (largestNum / significantDigit > 0){

		int bucket[10] = { 0 };

		// Counts the number of "keys" or digits that will go into each bucket
		for (i = 0; i < size; i++)
			bucket[(array[i] / significantDigit) % 10]++;

		/**
		 * Add the count of the previous buckets,
		 * Acquires the indexes after the end of each bucket location in the array
		 * Works similar to the count sort algorithm
		 **/
		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];

		// Use the bucket to fill a "semiSorted" array
		for (i = size - 1; i >= 0; i--)
			semiSorted[--bucket[(array[i] / significantDigit) % 10]] = array[i];


		for (i = 0; i < size; i++)
			array[i] = semiSorted[i];

		// Move to next significant digit
		significantDigit *= 10;

	}
	free(semiSorted);
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

	radix_sort(A, n);

	// Записывае данные и закрываем файлы

	for (int i = 0; i < n; ++i)
		fprintf(fout, "%d ", A[i]);

	fclose(fout);
	free(A);
	return 0;
}
