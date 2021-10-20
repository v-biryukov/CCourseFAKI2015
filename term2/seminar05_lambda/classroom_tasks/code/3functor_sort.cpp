#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Compare {
private:
public:
	bool operator()(int a, int b) {
		return a % 10 > b % 10;
	}
};

ostream& operator<<(ostream& stream, const vector<int>& right) {
	for (size_t i = 0; i < right.size(); ++i) {
		cout << right[i] << " ";
	}
	return stream;
}


int main() {
	vector<int> v {65, 43, 26, 74, 6, 72, 84, 1, 4, 63, 74};
	cout << v << endl;

	sort(v.begin(), v.end(), Compare());
	cout << v << endl;
}