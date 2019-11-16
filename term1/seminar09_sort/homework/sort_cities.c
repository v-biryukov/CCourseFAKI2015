#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct city
{
	char name[50];
	float latitude, longitude;
	char country[50];
	int population;
};
typedef struct city City;


void quicksort_population(City array[], int lo, int hi)
{
	if (hi - lo > 1)
	{
		City pivot = array[hi - 1];
		int j = lo;
		for (int i = lo; i < hi; i++)
			if (array[i].population <= pivot.population)
			{
				City temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				j++;
			}
		quicksort_population(array, lo, j - 1);
		quicksort_population(array, j, hi);
	}
}

void quicksort_latitude(City array[], int lo, int hi)
{
	if (hi - lo > 1)
	{
		City pivot = array[hi - 1];
		int j = lo;
		for (int i = lo; i < hi; i++)
			if (array[i].latitude <= pivot.latitude)
			{
				City temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				j++;
			}
		quicksort_latitude(array, lo, j - 1);
		quicksort_latitude(array, j, hi);
	}
}

void quicksort_name(City array[], int lo, int hi)
{
	if (hi - lo > 1)
	{
		City pivot = array[hi - 1];
		int j = lo;
		for (int i = lo; i < hi; i++)
			if (strcmp(array[i].name, pivot.name) <= 0)
			{
				City temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				j++;
			}
		quicksort_name(array, lo, j - 1);
		quicksort_name(array, j, hi);
	}
}

void save_to_file(char filename[], City cities[], int n)
{
	FILE* f = fopen(filename, "w");
	fprintf(f, "%d\n", n);
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "%s,%f,%f,%s,%d\n", cities[i].name, cities[i].latitude, cities[i].longitude, 
									   cities[i].country, cities[i].population);
	}
	fclose(f);
}

void read_from_file(char filename[], City** pcities, int* pn)
{
	FILE* f = fopen(filename, "r");
	fscanf(f, "%d\n", pn);

	*pcities = (City*)malloc((*pn) * sizeof(City));
	for (int i = 0; i < (*pn); i++)
	{
		fscanf(f, "%[^,],%f,%f,%[^,],%d\n", &(*pcities)[i].name, &(*pcities)[i].latitude, &(*pcities)[i].longitude, 
											&(*pcities)[i].country, &(*pcities)[i].population);
	}
	fclose(f);
}

int main()
{
	int n;
	City* cities;
	read_from_file("worldcities.txt", &cities, &n);


	quicksort_population(cities, 0, n);
	save_to_file("sorted_by_population.txt", cities, n);

	quicksort_latitude(cities, 0, n);
	save_to_file("sorted_by_latitude.txt", cities, n);

	quicksort_name(cities, 0, n);
	save_to_file("sorted_by_name.txt", cities, n);
	
	free(cities);
	return 0;
}