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
	Actor actors[5000];
};
typedef struct movie_database MovieDatabase;

// Функция, которая печатает информацию об одном актере
void print_actor(FILE* stream, const Actor* a)
{
	fprintf(stream, "%10s %15s. Height: %d cm. Birth date: %02d/%02d/%d. Birth Address: %s, %s, %s\n", a->name, a->surname,
		   a->height, a->birth_date.day, a->birth_date.month, a->birth_date.year, 
		   a->birth_address.country, a->birth_address.region, a->birth_address.city);
}

// Функция, которая печатает информацию об одном фильме
void print_movie(FILE* stream, const Movie* a)
{
	fprintf(stream, "%20s. Rating: %.3lf. Release date: %02d/%02d/%d.\n", a->title, a->rating,
		    a->release_date.day, a->release_date.month, a->release_date.year);
}

// Считывает актёров и возвращает их количество
// Главное чтобы массив actors был достаточно вместителен (иначе будет ошибка)
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
	}
	fclose(fin);
	return number_of_actors;
}

// Считывает фильмы и возвращает их количество
// Главное чтобы массив movies был достаточно вместителен (иначе будет ошибка)
int read_movies_from_file(char* filename, Movie* movies)
{
	FILE* fin = fopen(filename, "r");
	int number_of_movies;
	fscanf(fin, "%d", &number_of_movies);
	for (int i = 0; i < number_of_movies; ++i)
	{
		
		fscanf(fin, "%[^,],%d/%d/%d,%lf,%d,", movies[i].title, &movies[i].release_date.day, 
			&movies[i].release_date.month, &movies[i].release_date.year, &movies[i].rating, &movies[i].crew_size);
		for (int j = 0; j < movies[i].crew_size; ++j)
		{
			fscanf(fin, "%d", &movies[i].crew[j]);
		}
	}
	fclose(fin);
	return number_of_movies;
}

// Считываем все данные из файлов в структуру типа MovieDatabase,
// которая содержится по адресу pmd (сокр. от Pointer to Movie Database)
void read_database(MovieDatabase* pmd, char* actors_file_name, char* movies_file_name)
{
	pmd->number_of_actors = read_actors_from_file(actors_file_name, pmd->actors);
	pmd->number_of_movies = read_movies_from_file(movies_file_name, pmd->movies);
}

// Печатает информацию о фильме под номером movie_id (номер в массиве movies структуры md)
// Кроме информации о самом фильме, печатает также всех актёров 
void print_movie_descriptive(FILE* stream, const MovieDatabase* pmd, int movie_id)
{
	print_movie(stdout, &pmd->movies[movie_id]);
	printf("Actors:\n");
	for (int i = 0; i < pmd->movies[movie_id].crew_size; ++i)
	{
		printf("\t");
		print_actor(stdout, &pmd->actors[pmd->movies[movie_id].crew[i]]);
	}
	printf("\n");
}


void print_all_movies_by_actor(FILE* stream, const MovieDatabase* pmd, int actor_id)
{
	print_actor(stdout, &pmd->actors[actor_id]);
	for (int i = 0; i < pmd->number_of_movies; ++i)
	{
		for (int j = 0; j < pmd->movies[i].crew_size; ++j)
		{
			if (pmd->movies[i].crew[j] == actor_id)
			{
				print_movie_descriptive(stream, pmd, i);
			}
		}
	}
}


void find_best_actor(const MovieDatabase* pmd)
{
	int actor_total_movies[5000] = {};
	double actor_ratings[5000] = {};
	for (int i = 0; i < pmd->number_of_movies; ++i)
	{
		for (int j = 0; j < pmd->movies[i].crew_size; ++j)
		{
			int current_actor_id = pmd->movies[i].crew[j];
			actor_total_movies[current_actor_id]++;
			actor_ratings[current_actor_id] += pmd->movies[i].rating;
		}
	}

	for (int i = 0; i < pmd->number_of_actors; ++i)
	{
		actor_ratings[i] /= actor_total_movies[i];
	}

	int best_actor_id = 0;
	double best_rating = 0;
	for (int i = 0; i < pmd->number_of_actors; ++i)
	{
		if (actor_ratings[i] > best_rating)
		{
			best_actor_id = i;
			best_rating = actor_ratings[i];
		}
	}

	printf("Best actor:\n");
	print_actor(stdout, &pmd->actors[best_actor_id]);
	printf("Number of movies = %d; Average rating = %lf\n", actor_total_movies[best_actor_id], best_rating);
}


int main()
{
	MovieDatabase md;
	printf("%llu\n", sizeof(md));
	read_database(&md, "actors.csv", "movies.csv");
	while (1)
	{
		printf("Enter movie id (no more than 4000):\n");
		int id;
		scanf("%d", &id);
		print_movie_descriptive(stdout, &md, id);
	}
}