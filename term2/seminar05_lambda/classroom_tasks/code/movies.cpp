#include <iostream>
#include <vector>
using namespace std;

struct Date {
    int day, month, year;
};

struct Movie {
    std::string title;
    int running_time;
    float rating;
    Date release_date;
};


// Перегруженный оператор для печати структуры Date
ostream& operator<<(ostream& stream, const Date& right) {
    stream << right.day << "." << right.month << "." << right.year;
    return stream;
}

// Перегруженный оператор для печати структуры Movie
ostream& operator<<(ostream& stream, const Movie& right) {
    stream << right.title << ". Running time:" << right.running_time 
        <<". Rating: " << right.rating << ". Release date: " << right.release_date;
    return stream;
}

// Перегруженный оператор для печати вектора структур Movie
ostream& operator<<(ostream& stream, const vector<Movie>& array) {
    for (const auto& m : array) {
        cout << m << endl;
    }
    return stream;
}


int main() {
    vector<Movie> movies {{"The Godfather", 175, 8.735, {14, 3, 1972}},
                          {"The Shawshank Redemption", 142, 9.112, {10, 9, 1994}},
                          {"Fight Club", 175, 8.651, {10, 9, 1999}},
                          {"The Matrix", 131, 8.491, {24, 3, 1999}},
                          {"Pulp Fiction", 154, 8.620, {19, 5, 1994}},
                          {"Citizen Kane", 119, 7.826, {1, 5, 1941}},
                          {"A Clockwork Orange", 137, 7.959, {19, 12, 1971}},
                          {"2001: A Space Odyssey", 149, 7.988, {2, 4, 1968}},
                          {"Finding Nemo", 175, 7.862, {30, 05, 2003}},
                          {"Vzlomat blogerov", 90, 1.029, {10, 11, 2016}} };

    cout << movies;
}