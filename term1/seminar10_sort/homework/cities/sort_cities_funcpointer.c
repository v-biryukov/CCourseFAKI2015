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


void quicksort(City array[], int lo, int hi, int (*cmp)(City*, City*))
{
	if (hi - lo > 1)
	{
		City pivot = array[hi - 1];
		int j = lo;
		for (int i = lo; i < hi; i++)
			if (cmp(&array[i], &pivot) >= 0)
			{
				City temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				j++;
			}
		quicksort(array, lo, j - 1, cmp);
		quicksort(array, j, hi, cmp);
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


int cmp_population(City* left, City* right)
{
	return left->population - right->population;
}

int cmp_latitude(City* left, City* right)
{
	if (left->latitude < right->latitude)
		return -1;
	else if (left->latitude > right->latitude)
		return 1;
	else
		return 0;
}

int cmp_name(City* left, City* right)
{
	return -strcmp(left->name, right->name);
}

int main()
{
	int n;
	City* cities;
	read_from_file("worldcities.txt", &cities, &n);


	quicksort(cities, 0, n, cmp_population);
	save_to_file("sorted_by_population.txt", cities, n);

	quicksort(cities, 0, n, cmp_latitude);
	save_to_file("sorted_by_latitude.txt", cities, n);

	quicksort(cities, 0, n, cmp_name);
	save_to_file("sorted_by_name.txt", cities, n);
	
	free(cities);
	return 0;
}