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
	int gender;
	Date birth_date;
	Address birth_address;
};
typedef struct actor Actor;


void print_actor(const Actor* a)
{
	printf("%10s %10s. Birth date: %02d/%02d/%d. Birth Address: %s, %s, %s\n", a->name, a->surname,
		   a->birth_date.day, a->birth_date.month, a->birth_date.year, 
		   a->birth_address.country, a->birth_address.region, a->birth_address.city);
}

void print_actors(const Actor* actors, int number_of_actors)
{
	for (int i = 0; i < number_of_actors; i++)
	{
		print_actor(&actors[i]);
	}
}


int main()
{
	printf("Actror Size = %d\n", sizeof(Actor));
	Actor actors[10] = { {"Ivan", "Ivanov",  0, {5, 10, 1977},         {"Russia", "Moscow Oblast", "Dolgoprudny"}},
						 {"Olga", "Petrova", 1, {17, 2, 1981},         {"Russia", "Chelyabinsk Oblast", "Miass"}},
						 {"John", "Stone", 0,  {11, 8, 1986},          {"England", "East Sussex", "Rye"}},
						 {"Andrea", "Muller", 1,  {16, 1, 1996},       {"Germany", "Schleswig-Holstein", "Lubeck"}},
						 {"Isabella", "Rodriguez", 1,  {11, 7, 1992},  {"Spain", "La Rioja", "Logrono"}},
						 {"Kane", "Sato", 0,  {21, 12, 2001},          {"Japan", "Chiba Prefecture", "Mobara"}}
	};

	print_actors(actors, 6);
}