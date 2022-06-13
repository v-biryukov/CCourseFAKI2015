#include <iostream>
using std::cout, std::endl;


struct Movie 
{
    char title[100];
    int releaseYear;
    int numVotes;
    float rating;

    void setReleaseYear(int year)
    {
        releaseYear = year;
        if (releaseYear < 1900)
            releaseYear = 1900;
    }

    void addVote(int x)
    {
        rating = (rating * numVotes + x) / (numVotes + 1);
        numVotes += 1;
    }

    void print() const
    {
        cout << title << ", releaseYear = " << releaseYear << ", rating = " << rating 
             << " (" << numVotes << " votes)" << endl;  
    }
};




int main() 
{
    Movie a = {"Dark City", 2000, 4, 8.0};
    a.print();

    a.setReleaseYear(1998);
    a.print();

    a.setReleaseYear(1600);
    a.print();

    a.addVote(10.0);
    a.print();
}

