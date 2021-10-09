#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "utils.h"


void read_list_of_words(char* filename, char*** pwords, int* p_number_of_words)
{
	FILE* fin = fopen(filename, "r");
	if (fin == NULL)
	{
		fprintf(stderr, "Can't open file %s!\n", filename);
		exit(1);
	}
	*p_number_of_words = count_number_of_lines_in_file(fin);

	*pwords = (char**)malloc((*p_number_of_words) * sizeof(char*));

	char temp_string[50];
	for (int i = 0; i < *p_number_of_words; ++i)
	{
		fscanf(fin, "%50s", temp_string);
		(*pwords)[i] = (char*)malloc(strlen(temp_string) + 1);
		capitalize(temp_string);
		strcpy((*pwords)[i], temp_string);
	}

	fclose(fin);
}

void delete_words(char** words, int number_of_words)
{
	for (int i = 0; i < number_of_words; ++i)
	{
		free(words[i]);
	}
	free(words);
}




void generate_movie_titles(FILE* fout, int number_of_titles, char* path_to_actors_file)
{
	srand(time(0));

	int number_of_nouns;
	char** nouns;
	read_list_of_words("data/nouns.txt", &nouns, &number_of_nouns);

	int number_of_adjectives;
	char** adjectives;
	read_list_of_words("data/adjectives.txt", &adjectives, &number_of_adjectives);

	int number_of_verbs;
	char** verbs;
	read_list_of_words("data/verbs.txt", &verbs, &number_of_verbs);


	int number_of_actors;
	Actor* actors;
	read_actors(path_to_actors_file, &actors, &number_of_actors);

	fprintf(fout, "%d\n", number_of_titles);
	for (int i = 0; i < number_of_titles; ++i)
	{
		char title[50] = {};

		int title_type = rand() % 4;
		if (title_type == 0)
		{
			strcat(title, "The ");
			strcat(title, nouns[rand() % number_of_nouns]);
		}
		else if (title_type == 1)
		{
			strcat(title, adjectives[rand() % number_of_adjectives]);
			strcat(title, " ");
			strcat(title, nouns[rand() % number_of_nouns]);
		}
		else if (title_type == 2)
		{
			strcat(title, nouns[rand() % number_of_nouns]);
			strcat(title, " And The ");
			strcat(title, nouns[rand() % number_of_nouns]);
		}

		else if (title_type == 3)
		{
			strcat(title, verbs[rand() % number_of_verbs]);
			strcat(title, " The ");
			strcat(title, nouns[rand() % number_of_nouns]);
		}

		fprintf(fout, "%s,", title);

		Date release_date = get_random_date(1970, 2018);
		fprintf(fout, "%d/%d/%d,", release_date.day, release_date.month, release_date.year);

		double rating = random_normal_value(6.0, 2.0);
		if (rating < 0)
			rating *= -1;
		if (rating > 10)
			rating = 10 - 2 * (rating - 10);
		fprintf(fout, "%.3f,", rating);
		
		int number_of_chosen_actors =  2 + rand() % 15;
		fprintf(fout, "%d,", number_of_chosen_actors);
		int j = 0;
		while (j < number_of_chosen_actors)
		{
			int actor_id = rand() % number_of_actors;
			
			if (is_date_later(release_date, actors[actor_id].birth_date))
			{
				fprintf(fout, "%d", actor_id);
				if (j != number_of_chosen_actors - 1)
				{
					fprintf(fout, " ");
				}
				j++;
			}
		}

		fprintf(fout, "\n");
	}

	free(actors);
	delete_words(nouns, number_of_nouns);
	delete_words(verbs, number_of_verbs);
	delete_words(adjectives, number_of_adjectives);
}



int main(int argc, char** argv)
{
	srand(time(0));
	if (argc != 4)
	{
		printf("Usage:\n");
		printf("./a.out <number of movies to generate> <actors_file> <file to save movies>\n");
		exit(1);
	}
	int number_of_movies;
	sscanf(argv[1], "%d", &number_of_movies);

	FILE* fout = fopen(argv[3], "w");
	generate_movie_titles(fout, number_of_movies, argv[2]);


	fclose(fout);
}