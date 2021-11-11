#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& stream, const std::vector<int>& v) {
    for (std::vector<int>::const_iterator it = v.cbegin(); it != v.cend(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return stream;
}


int main() {
    std::vector<int> a{ 1, 2, 3 };
    std::back_insert_iterator<std::vector<int>> it{ a };
    it = 4;
    it = 5;
    std::cout << a;
}