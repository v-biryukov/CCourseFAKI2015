#include <iostream>
#include <cstdlib>
#include <fstream>
using std::cout, std::endl;

/*
    В языке C++ тоже иногда применяются коды возврата

    malloc работает также как и в языке C

    Чтение из файла с помощью std::ifstream, хоть и не возвращает код,
    но устанавливает состояние объекта таким образом, чтобы метод fail возвращал true

*/

int main()
{
    void* p = std::malloc(100000000000000);
    if (p == nullptr)
    {
        cout << "Error: can't allocate enough memory.\n";
    }
    std::free(p);



    std::ifstream file("file_doesnt_exist.txt");
    if (file.fail())
    {
        cout << "Error: can't open file.\n";
    }
}

