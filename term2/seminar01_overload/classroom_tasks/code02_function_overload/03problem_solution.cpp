#include <iostream>
using std::cout, std::endl;

/*
    Задача:

        Напишите несколько перегруженных функций под названием printType

        Эти функции должны печатать тип переменной, которая поступает на вход
    

        printType(15)       должен напечатать int
        printType(1.5)      должен напечатать double
        printType(1.5f);    должен напечатать float
        printType("Hello"); должен напечатать char[]

        book b = {"War and Peace", 900, 1200};
        printType(b);       должен напечатать book

*/

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

void printType(const char a[])
{
    cout << "char[]" << endl;
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