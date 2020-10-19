#pragma once
#include <stdio.h>
#include <stdlib.h>


struct city
{
	char name[30];
	char region[50];
	int population;
};
typedef struct city City;

void read_cities(char* filename, City* cities, int* p_number_of_cities)
{
	FILE* fin = fopen(filename, "r");
	char temp[1000];
	fscanf(fin, "%[^\n]\n", temp);

	int city_id = 0;
	while (fscanf(fin, "%[^,],%[^,],%d\n", cities[city_id].name, cities[city_id].region, &cities[city_id].population) != EOF)
	{
		city_id++;
		//printf("%s, %s, %d\n", cities[city_id].name, cities[city_id].region, cities[city_id].population);
	}
	*p_number_of_cities = city_id;
}


int get_total_population(City* cities, int number_of_cities)
{
	int total_population = 0;
	for (int i = 0; i < number_of_cities; ++i)
	{
		total_population += cities[i].population;
	}
	return total_population;
}


int get_random_city(City* cities, int number_of_cities)
{
	int total_population = get_total_population(cities, number_of_cities);
	int random = (rand() * RAND_MAX + rand()) % total_population;

	int city_id = 0;
	while (random > 0)
	{
		random -= cities[city_id].population;
		city_id++;
	}
	return city_id - 1;
}
