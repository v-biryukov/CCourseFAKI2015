#include <iostream>

int getMax(int a, int b) {
    return a > b ? a : b;
}

long long getMax(long long a, long long b) {
    return a > b ? a : b;
}

float getMax(float a, float b) {
    return a > b ? a : b;
}

double getMax(double a, double b) {
    return a > b ? a : b;
}


int main() {
    float x = 5.5;
    float y = 1.7;
    std::cout << getMax(x, y) << std::endl;
}