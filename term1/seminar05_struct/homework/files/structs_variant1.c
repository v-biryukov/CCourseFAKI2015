#include <stdio.h>

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

	Date birth_date;
	Address birth_address;

	int gender;
	int occupation;
};
typedef struct actor Actor;


struct movie
{
	char title[50];
	Date release_date;
	double rating;

	Actor director;
	Actor actors[20];
};
typedef struct movie Movie;


struct movie_database
{
	int number_of_movies;
	Movie movies[500];
};
typedef struct movie_database MovieDatabase;


int main()
{
	printf("Movie Size = %d\n", sizeof(Movie));
	printf("Movie Database Size = %d\n", sizeof(MovieDatabase));
}