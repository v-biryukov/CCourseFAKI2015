#include <iostream>
using std::cout, std::endl;

struct book 
{
    char title[50];
    float price;
    int pages;
};


void printType(int a)
{
    cout << "int" << endl;
}

void printType(double a)
{
    cout << "double" << endl;
}

void printType(float a)
{
    cout << "float" << endl;
}

void printType(const char* a)
{
    cout << "const char*" << endl;
}

void printType(const book& a)
{
    cout << "book" << endl;
}



int main() 
{
    printType(15);
    printType(1.5);
    printType(1.5f);
    printType("Hello");

    book b = {"War and Peace", 900, 1200};
    printType(b);
}