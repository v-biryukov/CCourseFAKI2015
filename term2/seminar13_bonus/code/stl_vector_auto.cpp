#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> A;
	A.push_back(5);
	A.push_back(2);
	A.push_back(9);
	A.push_back(7);

	sort(A.begin(), A.end());

	for (auto itr = A.begin(); itr < A.end(); ++itr)
		cout << *itr << "\n";


	
	return 0;
}