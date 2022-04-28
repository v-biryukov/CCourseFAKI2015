#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& stream, const std::vector<int>& v) 
{
    for (std::vector<int>::const_iterator it = v.cbegin(); it != v.cend(); it++)
        std::cout << *it << " ";

    std::cout << std::endl;
    return stream;
}


int main() 
{
    std::vector<int> a { 4, 8, 15, 16, 23, 42 };
    
    std::vector<int> b(a.size());
    std::cout << b;

    std::copy(a.begin(), a.end(), b.begin());
    std::cout << b;
}