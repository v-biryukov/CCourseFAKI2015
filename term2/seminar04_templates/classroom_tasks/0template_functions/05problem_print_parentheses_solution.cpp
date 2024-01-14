#include <iostream>
#include <string>

#include "book.h"
#include "complex.h"

using std::cout, std::endl;


template <typename T>
void printInParentheses(const T& a)
{
    std::cout << "(" << a << ")" << "\n";
}


int main() 
{
    printInParentheses(3);

    mipt::Complex a {4, 2};
    printInParentheses(a);

    Book b {"Harry Potter", 500, 400.0};
    printInParentheses(b);
}
