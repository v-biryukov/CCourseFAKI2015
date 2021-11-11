#include <iostream>
#include <vector>
#include <iomanip>
using std::cout;
using std::endl;

struct Book {
    std::string title;
    int pages;
    float price;
};
std::ostream& operator<<(std::ostream& stream, const Book& b) {
    cout << std::setw(15) << std::left << b.title << ", Pages = " << b.pages << ", Price = " << b.price;
    return stream;
}





/*
    Примеры copy list initialization
*/

bool is_more_expensive(Book b, float money) {
    return b.price > money;
}

Book get_war_and_peace() {
    return {"War and Peace", 1225, 1500};
}

int main() {
    Book a {"The Queen of Spades", 310, 700};
    cout << a << endl << endl;;

    // После оператора присваивания:
    a = {"Harry Potter", 223, 500};
    cout << a << endl << endl;

    // В аргументах функции:
    if (is_more_expensive({"Catch-22", 453, 800}, 700)) {
        cout << "This book is more expensive" << endl << endl;
    }

    // Возращаемое значение функции:
    a = get_war_and_peace();
    cout << a << endl;
}


/*
    Задание:
    1) Поменяйте структуру Book на класс Book
       Поля сделайте приватными и добавьте конструктор от трёх аргументов
       Будет ли работать код выше

    2) Структура для филима имеет вид: 
        struct Movie {
            std::string title;
            float price;
            std::vector<int> ratings;
        };
        где ratings - вектор, содержащий оценки, поставленные этой игре
        Проверьте, будет ли работать для такой структуры copy list initialization

        Movie a = {"Matrix", 500, {9, 7, 8, 10, 9, 10}};
        a = {"Venom 2", 100, {5, 6, 4, 5, 7, 5, 4, 3, 1}};

*/