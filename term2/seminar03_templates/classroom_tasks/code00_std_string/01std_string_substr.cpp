#include <iostream>
#include <string>
using std::cout, std::endl;


int main()
{
    std::string s = "Sapere Aude";
    cout << s << endl;
    cout << s.size() << endl;
    cout << s.capacity() << endl;


    std::string s2 = s.substr(2, 5);
    cout << s2 << endl;


    std::string s3 = s.insert(7, "aaaa ");
    cout << s3 << endl;

}


/*
    Задача

        Напишите функцию, которая будет принимать на вход строку по ссылке и изменять её так,
        чтобы после каждого слова добавлялся восклицательный знак

        "Cat Dog Mouse"  -->  "Cat! Dog! Mouse!"


*/