#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "generate_cities.h"
#include "generate_random_names.h"

struct date
{
	int day, month, year;
};
typedef struct date Date;


struct address
{
	char country[20];
	char region[20];
	char city[20];
};
typedef struct address Address;


struct actor
{
	char name[32];
	char surname[32];
	int gender;
	Date birth_date;
	Address birth_address;
};
typedef struct actor Actor;


void generate_random_actors(FILE* fout, int number_of_names, char* path_to_female_names, char* path_to_male_names, char* path_to_surnames, char* path_to_cities)
{
	srand(time(0));
	int number_of_female_names;
	char female_names[200][MAX_NAME_LENGTH];
	int number_of_male_names;
	char male_names[200][MAX_NAME_LENGTH];

	int number_of_surnames;
	char surnames[2000][MAX_NAME_LENGTH];

	read_names(path_to_female_names, female_names, &number_of_female_names);
	read_names(path_to_male_names, male_names, &number_of_male_names);
	read_names(path_to_surnames, surnames, &number_of_surnames);


	City cities[1000];
	int number_of_cities;
	read_cities(path_to_cities, cities, &number_of_cities);

	for (int i = 0; i < number_of_names; i++)
	{
		int gender = rand() % 2;
		int surname_id = rand() % number_of_surnames;
		if (gender == 0)
		{
			int name_id = rand() % number_of_male_names;
			fprintf(fout, "%s,%s,", male_names[name_id], surnames[surname_id]);
		}
		else
		{
			int name_id = rand() % number_of_female_names;
			char current_surname[MAX_NAME_LENGTH];
			strcpy(current_surname, surnames[surname_id]);
			convert_male_surname_to_female(current_surname);
			fprintf(fout, "%s,%s,", female_names[name_id], current_surname);
		}

		fprintf(fout, "%d,", gender);
		int random_city_id = get_random_city(cities, number_of_cities);
		fprintf(fout, "Russia,%s,%s\n", cities[random_city_id].region, cities[random_city_id].name);
	}
}




int main(int argc, char** argv)
{
	if (argc != 3)
	{
		printf("Usage:\n");
		printf("generate_random_actors <number of names> <file to save the names>\n");
		return 1;
	}

	int number_of_names_to_generate;
	sscanf(argv[1], "%d", &number_of_names_to_generate);

	FILE* fout = fopen(argv[2], "w");

	generate_random_actors(fout, number_of_names_to_generate, "data/female_names.txt", "data/male_names.txt", 
															 "data/surnames.txt", "data/russian_cities.csv");

	fclose(fout);
}

