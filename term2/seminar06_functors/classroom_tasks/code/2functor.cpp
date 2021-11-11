#include <iostream>
using namespace std;

class Functor {
private:
	int count;
public:
	Functor() {
		count = 0;
	}
	void operator()() {
		count += 1;
		cout << "Functor call # " << count << endl;
	}
};

int main() {
	Functor f;
	for (int i = 0; i < 10; ++i) {
		f();
	}
}