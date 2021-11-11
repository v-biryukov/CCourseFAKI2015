#include <iostream>

int main() {

	// Тип nums будет std::initializer_list<int>
	auto nums = {5, 1, 2, 4, 6};


	for (auto el : nums) {
		std::cout << el << " ";
	}
}