#include <iostream>
#include <utility>
using std::cout, std::endl;

class Cat
{
private:
    int id = 0;
public:
    Cat() : id{0} {}
    Cat(int id) : id{id} {}
    
    Cat& operator=(const Cat& b) & {cout << "First" << endl; return *this;}
    Cat& operator=(const Cat& b) && {cout << "Second" << endl; return *this;}
    
    friend std::ostream& operator<<(std::ostream& out, const Cat& c);
};
std::ostream& operator<<(std::ostream& out, const Cat& c)
{
    out << c.id;
    return out;
}



int main()
{
    Cat a = 10;
    Cat b = 20;
    
    std::move(a) = b;
    
    cout << a << endl;
}
