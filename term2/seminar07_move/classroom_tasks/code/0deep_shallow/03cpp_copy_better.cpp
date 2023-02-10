/*
    Нужно отметить, что в абсолютном большинстве случаев прописывать для вашего объекта  
    конструкторы копирования, перегруженные операторы присваивания другие особые методы не нужно.

    Вместо этого можно воспользоваться классами из стандартной библиотеки языка C++, а также тем,
    что если вы не пропишите особые методы, то они сгенерируются самостоятельно.
    Например, если вы не пропишите конструктор копирования, то компилятор сгенирирует конструктор
    копирования, который будет копировать все поля одного объекта в соответствующие поля другого объекта.

    В данном примере мы используем строку std::string.
    При копировании объекта Book, будут копироваться все поля объекта Book, и, соответственно, будет копироваться
    объект std::string и, следовательно, будет вызываться конструктор копирования класса std::string.
    Таким образом, класс std::string берёт всю сложную работу по выделению/освобождению памяти на себя.
*/

#include <iostream>
#include <string>
using std::cout, std::endl;

struct Book
{
private:
    std::string title;
    int pages;
    float price;

public:

    Book(const std::string& atitle, int apages, float aprice) : pages {apages}, price {aprice}, title{atitle}
    {
    }

    void setPrice(float newPrice)
    {
        price = newPrice;
    }

    void setTitle(const std::string& newTitle)
    {
        title = newTitle;
    }

    friend std::ostream& operator<<(std::ostream& out, const Book& b);
};

std::ostream& operator<<(std::ostream& out, const Book& b)
{
    out << "Title: " << b.title << ", pages: " << b.pages << ", price " << b.price;
    return out;
}




int main()
{
    cout << "Book b is copy of Book a:" << endl;
    Book a {"Harry Potter", 500, 200};
    Book b = a;
    cout << "a) " << a << endl;
    cout << "b) " << b << endl;


    cout << endl << "Changing price of book b:" << endl;
    b.setPrice(700);
    cout << "a) " << a << endl;
    cout << "b) " << b << endl;


    cout << endl << "Changing title of book b:" << endl;
    b.setTitle("Barry Potter");
    cout << "a) " << a << endl;
    cout << "b) " << b << endl;
}