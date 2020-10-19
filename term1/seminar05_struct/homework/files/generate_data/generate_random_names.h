#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

int count_number_of_lines_in_file(FILE* file)
{
	int position = ftell(file);
	fseek(file, 0, SEEK_SET);

	int c;
	int number_of_lines = 0;
	while ((c = fgetc(file)) != EOF) 
	{
		if (c == '\n')
			number_of_lines++;
	}

	fseek(file, position, SEEK_SET);
	return number_of_lines;
}

void read_names(char* filename, char surnames[][MAX_NAME_LENGTH], int* p_number_of_surnames)
{
	FILE* fin = fopen(filename, "r");
	if (fin == NULL)
	{
		fprintf(stderr, "Error! Can't open file %s\n", filename);
		exit(1);
	}
	*p_number_of_surnames = count_number_of_lines_in_file(fin);

	for (int i = 0; i < *p_number_of_surnames; ++i)
	{
		fscanf(fin, "%20s", surnames[i]);
	}

	fclose(fin);
}

void convert_male_surname_to_female(char* surname)
{
	int n = strlen(surname);
	if ((surname[n-1] == 'v' && (surname[n-2] == 'o' || surname[n-2] == 'e')) || (surname[n-2] == 'i' && surname[n-1] == 'n'))
	{
		surname[n] = 'a';
		surname[n+1] = '\0';
	}
	else if (surname[n-1] == 'y')
	{
		surname[n-1] = 'a';
		surname[n]   = 'y';
		surname[n+1] = 'a';
		surname[n+2] = '\0';
	}
}


void generate_random_names(FILE* fout, int number_of_names, char* path_to_female_names, char* path_to_male_names, char* path_to_surnames)
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

	for (int i = 0; i < number_of_names; i++)
	{
		int gender = rand() % 2;
		int surname_id = rand() % number_of_surnames;
		if (gender == 0)
		{
			int name_id = rand() % number_of_male_names;
			fprintf(fout, "%s %s\n", male_names[name_id], surnames[surname_id]);
		}
		else
		{
			int name_id = rand() % number_of_female_names;
			char current_surname[MAX_NAME_LENGTH];
			strcpy(current_surname, surnames[surname_id]);
			convert_male_surname_to_female(current_surname);
			fprintf(fout, "%s %s\n", female_names[name_id], current_surname);
		}
	}
}

