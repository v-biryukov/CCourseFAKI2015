#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1{ 3 };
    std::vector<int> v2 = { 3 };
    std::vector<int> v3{ 3, 1 };
    std::vector<int> v4 = { 3, 1 };
    std::vector<int> v5(3, 1);


    std::cout << "v1 size " << v1.size() << std::endl;
    std::cout << "v2 size " << v2.size() << std::endl;
    std::cout << "v3 size " << v3.size() << std::endl;
    std::cout << "v4 size " << v4.size() << std::endl;
    std::cout << "v5 size " << v5.size() << std::endl;
}