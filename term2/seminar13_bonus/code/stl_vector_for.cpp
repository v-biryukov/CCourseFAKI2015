#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> A;
	A.push_back(5);
	A.push_back(2);
	A.push_back(9);
	A.push_back(7);

	//int B[] = {1, 2, 4, 5};

	for (int a : A)
		cout << a << "\n";

	return 0;
}