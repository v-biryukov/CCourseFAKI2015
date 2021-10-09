#include <iostream>

int getMaxi(int a, int b) {
	return a > b ? a : b;
}

long long getMaxll(long long a, long long b) {
	return a > b ? a : b;
}

float getMaxf(float a, float b) {
	return a > b ? a : b;
}

double getMaxd(double a, double b) {
	return a > b ? a : b;
}


int main() {
	float x = 5.5;
	float y = 1.7;
	std::cout << getMaxf(x, y) << std::endl;
}