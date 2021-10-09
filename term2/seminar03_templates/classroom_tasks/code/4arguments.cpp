#include <iostream>
using namespace std;


template <int n>
void counter() {
	for (int i = 0; i < n; ++i) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	counter<10>();
}