/*
    Рассмотрим операцию копирования вектора



    Известно, что класс std::vector не хранит элементы внутри объекта.
    Его элементы хранятся в выделенной памяти в куче, а внутри самого объекта вектора хранится только 
    указатель на эти данные, а также размер и вместимость вектора.



    Но, при копировании вектора, вызывается конструктор копирования вектора, внутри которого
    копируются, в том числе, и элементы, которые хранятся в куче.




    
    Схематическое изображение памяти:

        До копирования:                                        |    После копирования:
                                                               |                                         
         a                                                     |     a                                                         
        ╔═══════════╗          ╔════╤════╤════╤════╤════╗      |    ╔═══════════╗           ╔════╤════╤════╤════╤════╗   
        ║     *─────╫────────> ║ 10 │ 20 │ 30 │ 40 │ 50 ║      |    ║     *─────╫─────────> ║ 10 │ 20 │ 30 │ 40 │ 50 ║   
        ╟───────────╢          ╚════╧════╧════╧════╧════╝      |    ╟───────────╢           ╚════╧════╧════╧════╧════╝   
        ║     5     ║                                          |    ║     5     ║                                        
        ╟───────────╢                                          |    ╟───────────╢                                        
        ║     5     ║                                          |    ║     5     ║                                        
        ╚═══════════╝                                          |    ╚═══════════╝                                        
                                                               |                                                         
                                                               |                                                         
         b                                                     |     b                                                   
        ╔═══════════╗                                          |    ╔═══════════╗           ╔════╤════╤════╤════╤════╗   
        ║  nullptr  ║                                          |    ║     *─────╫─────────> ║ 10 │ 20 │ 30 │ 40 │ 50 ║   
        ╟───────────╢                                          |    ╟───────────╢           ╚════╧════╧════╧════╧════╝   
        ║     0     ║                                          |    ║     5     ║                                        
        ╟───────────╢                                          |    ╟───────────╢                                        
        ║     0     ║                                          |    ║     5     ║                                        
        ╚═══════════╝                                          |    ╚═══════════╝                                        
    
*/

#include <vector>
#include <iostream>
using std::cout, std::endl;

std::ostream& operator<<(std::ostream& out, const std::vector<int>& v)
{
    for (auto el : v)
        out << el << " ";
    return out;
}

int main()
{
    std::vector<int> a {10, 20, 30, 40, 50};
    std::vector<int> b; 

    b = a; // Копируем вектор a в вектор b

    cout << "vector a = " << a << endl;
    cout << "vector b = " << b << endl;

    cout << "vector a: size = " << a.size() << ", capacity = " << a.capacity() << ", pointer = " << &a[0] << endl;
    cout << "vector b: size = " << b.size() << ", capacity = " << b.capacity() << ", pointer = " << &b[0] << endl;
}