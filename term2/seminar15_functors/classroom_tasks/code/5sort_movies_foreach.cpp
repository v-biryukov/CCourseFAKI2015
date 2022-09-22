#include <iostream>
#include <vector>
#include <algorithm>
using std::cout, std::endl, std::vector, std::string;

struct Date 
{
    int day, month, year;
};

struct Movie 
{
    string title;
    int runningTime;
    float rating;
    Date releaseDate;
};


std::ostream& operator<<(std::ostream& stream, const Date& right) 
{
    stream << right.day << "." << right.month << "." << right.year;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Movie& right) 
{
    stream << right.title << ". Running time:" << right.runningTime  <<". Rating: " << right.rating << ". Release date: " << right.releaseDate;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const vector<Movie>& array) 
{
    for (const auto& m : array)
        cout << m << endl;
    return stream;
}


struct MovieRatingFunctor 
{
    operator()(const Movie& a, const Movie& b) 
    {
        return a.rating > b.rating;
    }
};

int main() 
{
    vector<Movie> movies {{"The Godfather", 175, 8.735, {14, 3, 1972}},
                          {"Fight Club", 175, 8.651, {10, 9, 1999}},
                          {"The Matrix", 131, 8.491, {24, 3, 1999}},
                          {"Vzlomat blogerov", 90, 1.029, {10, 11, 2016}},
                          {"Pulp Fiction", 154, 8.620, {19, 5, 1994}},
                          {"Citizen Kane", 119, 7.826, {1, 5, 1941}},
                          {"The Shawshank Redemption", 142, 9.112, {10, 9, 1994}},
                          {"A Clockwork Orange", 137, 7.959, {19, 12, 1971}},
                          {"2001: A Space Odyssey", 149, 7.988, {2, 4, 1968}},
                          {"Finding Nemo", 175, 7.862, {30, 05, 2003}} };

    cout << movies;


    MovieRatingFunctor mrf {};
    std::sort(movies.begin(), movies.end(), mrf);


    float rating = 0;
    std::for_each(movies.begin(), movies.end(), [&](const Movie& m) {rating += m.rating;});
    cout << rating / 10 << endl << endl;

    cout << movies;
}