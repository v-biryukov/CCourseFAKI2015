#include <iostream>

int imax(int a, int b) {
    return a > b ? a : b;
}

long long llmax(long long a, long long b) {
    return a > b ? a : b;
}

float fmax(float a, float b) {
    return a > b ? a : b;
}

double dmax(double a, double b) {
    return a > b ? a : b;
}


int main() {
    float x = 5.5;
    float y = 1.7;
    std::cout << fmax(x, y) << std::endl;
}