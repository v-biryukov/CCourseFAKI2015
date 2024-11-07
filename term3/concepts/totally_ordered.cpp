#include <iostream>
#include <compare>

struct Point {
    int x, y;

    // Определяем оператор spaceship
    auto operator<=>(const Point& other) const = default; // Используем default для автоматической генерации

    // Можно также реализовать свой собственный оператор, если требуется кастомизация
    // auto operator<=>(const Point& other) const {
    //     if (x != other.x) return x <=> other.x;
    //     return y <=> other.y;
    // }
};

template<std::totally_ordered T>
void compare(const T& a, const T& b) {
    if (a < b) {
        std::cout << "a < bn";
    } else if (b < a) {
        std::cout << "a > bn";
    } else {
        std::cout << "a == bn";
    }
}

int main() {
    Point p1{1, 2};
    Point p2{2, 3};
    Point p3{1, 2};

    compare(p1, p2); // Выведет: a < b
    compare(p2, p1); // Выведет: a > b
    compare(p1, p3); // Выведет: a == b

    return 0;
}
