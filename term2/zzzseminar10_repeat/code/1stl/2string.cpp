#include <sstream>
#include <fstream>

#include <iostream>
#include <string>

using std::cout;
using std::endl;


// Функция, которая загружает файл в строку
void load_file(std::string& str, char* filename)
{
    std::ifstream t(filename);
    std::stringstream buffer;
    buffer << t.rdbuf();
    str.assign(buffer.str());
}

int main()
{
    // Строки в стиле C во многом неудобны в использовании
    // В C++ есть более удобный инструмент для работы со строками: std::string
    // !! Различайте char s[20]     -- строка в стиле C, лучше не использовать в C++
    //               std::string s; -- строка C++
    
    // Создаём строки
    std::string s1("What one programmer can do in one month");
    std::string s2(", two programmers can do in two months");

    // Напечатайте строку s1 (с переносом строки). Ваш код:

    // Напечатайте 5-й символ строки s1. Ваш код:

    // Напечатайте сумму строк s1 и s2. Ваш код:


    // Напечатайте номер первого вхождения строки "can" в строку s1.
    // Используёте метод find(). Ваш код:













    // Задача со звёздочкой:
    std::string war_and_peace;
    // Считываем содержимое файла в переменную war_and_peace
    load_file(war_and_peace, "wp.txt");
    // Печатаем номер символа первого вхождения слова Pierre 
    cout << str.find("Pierre") << endl;
    // Печатаем 50 символов начиная с первого вхождения слова Pierre 
    cout << str.substr(str.find("Pierre"), 50) << endl;

    // Напечатайте все строки в которых встречается Pierre
    // Ваш код:

    
}