#include <memory>
#include <iostream>
using std::cout, std::endl;



int main()
{
    std::unique_ptr<int> a = std::make_unique<int>(123);
    cout << "unique_ptr a address = " << a.get() << endl;


    cout << "Moving a to b" << endl;
    std::unique_ptr<int> b = std::move(a);

    cout << "unique_ptr a address = " << a.get() << endl;
    cout << "unique_ptr b address = " << b.get() << endl;
}