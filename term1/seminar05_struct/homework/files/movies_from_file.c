#include <stdio.h>
#include <string.h>

struct date
{
	int day, month, year;
};
typedef struct date Date;


struct address
{
	char country[10];
	char region[50];
	char city[30];
};
typedef struct address Address;


struct actor
{
	char name[32];
	char surname[32];
	int gender; // пол: 0 - мужской, 1 - женский
	int height;
	Date birth_date;
	Address birth_address;
};
typedef struct actor Actor;

struct movie
{
	char title[50];
	Date release_date;
	double rating;

	// Будем хранить номера актеров из массива actors структуры типа MovieDatabase
	int crew_size;
	int crew[20];
};
typedef struct movie Movie;


struct movie_database
{
	int number_of_movies;
	Movie movies[5000];

	int number_of_actors;
	Actor actors[3000];
};
typedef struct movie_database MovieDatabase;


void print_actor(FILE* stream, const Actor* a)
{
	fprintf(stream, "%10s %15s. Height: %d cm. Birth date: %02d/%02d/%d. Birth Address: %s, %s, %s\n", a->name, a->surname,
		   a->height, a->birth_date.day, a->birth_date.month, a->birth_date.year, 
		   a->birth_address.country, a->birth_address.region, a->birth_address.city);
}

void print_actors(FILE* stream, const Actor* actors, int number_of_actors)
{
	for (int i = 0; i < number_of_actors; i++)
		print_actor(stream, &actors[i]);
	printf("\n");
}

void print_movie(FILE* stream, const Movie* a)
{
	fprintf(stream, "%20s. Rating: %.3lf. Release date: %02d/%02d/%d.\n", a->title, a->rating,
		    a->release_date.day, a->release_date.month, a->release_date.year);
}

// Считывает актёров и возвращает их количество
int read_actors_from_file(char* filename, Actor* actors)
{
	FILE* fin = fopen(filename, "r");
	int number_of_actors;
	fscanf(fin, "%d", &number_of_actors);

	for (int i = 0; i < number_of_actors; ++i)
	{
		fscanf(fin, "%[^,],%[^,],%d,%d,%d/%d/%d,%[^,],%[^,],%[^\n]\n",
			actors[i].name, actors[i].surname, &actors[i].gender, &actors[i].height,
			&actors[i].birth_date.day, &actors[i].birth_date.month, &actors[i].birth_date.year, 
			actors[i].birth_address.country, actors[i].birth_address.region, actors[i].birth_address.city);
		/*
		printf("%s,%s,%d,%d,%d/%d/%d,%s,%s,%s\n",
			actors[i].name, actors[i].surname, actors[i].gender, actors[i].height,
			actors[i].birth_date.day, actors[i].birth_date.month, actors[i].birth_date.year, 
			actors[i].birth_address.country, actors[i].birth_address.region, actors[i].birth_address.city);
		*/
	}
	fclose(fin);
	return number_of_actors;
}


// Считывает фильмы и возвращает их количество
int read_movies_from_file(char* filename, Movie* movies, MovieDatabase* md)
{
	FILE* fin = fopen(filename, "r");
	int number_of_movies;
	fscanf(fin, "%d", &number_of_movies);
	for (int i = 0; i < number_of_movies; ++i)
	{
		
		fscanf(fin, "%[^,],%d/%d/%d,%lf,%d,", movies[i].title, &movies[i].release_date.day, 
			&movies[i].release_date.month, &movies[i].release_date.year, &movies[i].rating, &movies[i].crew_size);
		//printf("mc %d: %d %d\n", i, movies[i].crew_size, md->actors[0].height);
		for (int j = 0; j < movies[i].crew_size; ++j)
		{
			fscanf(fin, "%d", &movies[i].crew[j]);
		}
	}
	fclose(fin);
	return number_of_movies;
}

void read_database(MovieDatabase* md, char* actors_file_name, char* movies_file_name)
{
	md->number_of_actors = read_actors_from_file(actors_file_name, md->actors);
	md->number_of_movies = read_movies_from_file(movies_file_name, md->movies, md);
}

void print_movie_db_simple(const MovieDatabase* md, int movie_id)
{
	print_movie(stdout, &md->movies[movie_id]);
}

void print_movie_db_descriptive(const MovieDatabase* md, int movie_id)
{
	print_movie(stdout, &md->movies[movie_id]);
	printf("Actors:\n");
	for (int i = 0; i < md->movies[movie_id].crew_size; ++i)
	{
		printf("\t");
		print_actor(stdout, &md->actors[md->movies[movie_id].crew[i]]);
	}
	printf("\n");
}


int main()
{
	MovieDatabase md;
	read_database(&md, "actors.csv", "movies.csv");
	while (1)
	{
		int movie_id;
		scanf("%d", &movie_id);
		print_movie_db_descriptive(&md, movie_id);
	}
}