#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TEXT_SIZE 1000
#define ARRAY_SIZE 10000

struct data
{
	char text[TEXT_SIZE];
};
typedef struct data Data;

void set_random_text(char* text)
{
	for (int i = 0; i < TEXT_SIZE - 1; i++)
	{
		text[i] = 65 + rand() % 58;
	}
}

void set_random_array(Data* array)
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		set_random_text(array[i].text);
	}
}

int cmp(const void* p1, const void* p2)
{
	return strcmp(((Data*)p1)->text, ((Data*)p2)->text);
}

int cmp_pointer(const void* p1, const void* p2)
{

	return strcmp((*((Data**)p1))->text, (*((Data**)p2))->text);
}


void print_first(Data* array, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%c", array[i].text[j]);
		}
		printf("\n");
	}
}

void print_first_by_pointer(Data** pointer_array, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%c", pointer_array[i]->text[j]);
		}
		printf("\n");
	}
}


int main()
{

	clock_t begin;
	clock_t end;
	

	srand(777);
	printf("\nGenerating data: \n");
	begin = clock();
	Data* array = (Data*)malloc(ARRAY_SIZE * sizeof(Data));
	set_random_array(array);
	print_first(array, 20, 40);
	end = clock();
	double generation_time_spent = (double)(end - begin) / CLOCKS_PER_SEC;


	printf("\nSorting: \n");
	begin = clock();
	qsort(array, ARRAY_SIZE, sizeof(Data), cmp);
	end = clock();
	double sorting_time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	print_first(array, 20, 40);

	srand(777);
	printf("\nGenerating old new data: \n");
	set_random_array(array);
	print_first(array, 20, 40);

	printf("\nSorting using pointer array: \n");
	Data** pointer_array = (Data**)malloc(ARRAY_SIZE * sizeof(Data*));
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		pointer_array[i] = array + i;
	}
	begin = clock();
	qsort(pointer_array, ARRAY_SIZE, sizeof(Data*), cmp_pointer);
	end = clock();
	double sorting_by_pointer_time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	print_first_by_pointer(pointer_array, 20, 40);


	printf("\nResults:\nGeneration Time: %lf seconds\nStruct qSorting Time: %lf seconds\nPointer qSorting Time: %lf seconds\n", 
		generation_time_spent, sorting_time_spent, sorting_by_pointer_time_spent);
}