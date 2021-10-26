#include <iostream>
using namespace std;

class Functor {
public:
	void operator()() {
		cout << "Functor operator() call" << endl;
	}
};

int main() {
	Functor f;
	f();
}