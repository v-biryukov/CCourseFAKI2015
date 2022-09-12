#pragma once

#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979

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
    int actors[20];
};
typedef struct movie Movie;

double random_normal_value(double mean, double dispersion)
{
    double u = (double)rand() / RAND_MAX;
    double v = (double)rand() / RAND_MAX;
    double x = sqrt(-2 * log(u)) * sin(2 * PI * v);
    return mean + x * dispersion;
}


void capitalize(char* word)
{
    if (word[0] >= 'a' && word[0] <= 'z')
    {
        word[0] -= 'a' - 'A';
    }
}

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


void read_actors(char* filename, Actor** pactors, int* p_number_of_actors)
{
    FILE* fin = fopen(filename, "r");
    if (fin == NULL)
    {
        printf("Can't open file %s!!\n", filename);
        exit(1);
    }
    fscanf(fin, "%d", p_number_of_actors);
    *pactors = (Actor*)malloc((*p_number_of_actors) * sizeof(Actor));
    for (int i = 0; i < *p_number_of_actors; ++i)
    {
        Actor* current = (*pactors) + i;
        fscanf(fin, "%[^,],%[^,],%d,%d,%d/%d/%d,%[^,],%[^,],%[^\n]\n",
            current->name, current->surname, &current->gender, &current->height,
            &current->birth_date.day, &current->birth_date.month, &current->birth_date.year, 
            current->birth_address.city, current->birth_address.region, current->birth_address.country);
    }
}


Date get_random_date(int start_year, int finish_year)
{
    Date d = {rand() % 30 + 1, rand() % 12 + 1, rand() % (finish_year - start_year) + start_year};
    return d;
}

int is_date_later(Date date, Date start)
{
    if (date.year > start.year)
        return 1;
    else if (date.month > start.month)
        return 1;
    else if (date.day > start.day)
        return 1;
    return 0;
}