#include <stdio.h>
#include <stdlib.h>

#include "generate_cities.h"

int main()
{
	City cities[1000];
	int number_of_cities;
	read_cities("data/russian_cities.csv", cities, &number_of_cities);
	printf("Total population = %d\n", get_total_population(cities, number_of_cities));

	for (int i = 0; i < 100; i++)
	{
		int random_city_id = get_random_city(cities, number_of_cities);
		printf("%s,%s\n", cities[random_city_id].name, cities[random_city_id].region);
	}
}