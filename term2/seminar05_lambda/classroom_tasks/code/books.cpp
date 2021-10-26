#include <iostream>
#include <vector>
using std::cout;
using std::endl;

struct Book {
    std::string title;
    std::string author;
    int pages;
    float price;
};


int main() {
    std::vector<Book> books {{"In Search of Lost Time", "Marcel Proust", 500, 1200},
                             {"The Odyssey", "Homer", 300, 700},
                             {"The Catcher in the Rye", "Jerome David Salinger", 400, 500},
                             {"Anna Karenina", "Leo Tolstoy", 800, 1000},
                             {"Catch-22", "Joseph Heller", 600, 900},
                             {"Faust", "Johann Goethe", 700, 1100},
                             {"The Castle", "Franz Kafka", 543, 100} };

}