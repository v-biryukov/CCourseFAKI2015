#include <iostream>
#include <vector>
using namespace std;


class GetDivisible {
private:
	int divisor;
	vector<int> nums;
public:
	GetDivisible(int divisor) : divisor(divisor) {
	}
	const GetDivisible& operator()(vector<int> v) {
		for (int i = 0; i < v.size(); ++i) {
			if (v[i] % divisor == 0) {
				nums.push_back(v[i]);
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& stream, const GetDivisible& right);
};

ostream& operator<<(ostream& stream, const GetDivisible& right) {
	for (int i = 0; i < right.nums.size(); ++i) {
		cout << right.nums[i] << " ";
	}
	return stream;
}



int main() {
	cout << GetDivisible(5)({5, 1, 41, 65, 32, 50}) << endl;;
}