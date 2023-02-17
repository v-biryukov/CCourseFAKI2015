/*
    Задача:

        Напишите несколько перегруженных функций под названием printType

        Эти функции должны печатать тип переменной, которая поступает на вход
    

        printType(15)       должен напечатать int
        printType(1.5)      должен напечатать double
        printType(1.5f);    должен напечатать float
        printType("Hello"); должен напечатать const char*

        book b = {"War and Peace", 900, 1200};
        printType(b);       должен напечатать book
*/

#include <iostream>
using std::cout, std::endl;

struct book 
{
    char title[50];
    float price;
    int pages;
};





int main() 
{
    printType(15);
    printType(1.5);
    printType(1.5f);
    printType("Hello");

    book b = {"War and Peace", 900, 1200};
    printType(b);
}