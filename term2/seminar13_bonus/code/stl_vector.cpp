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

	cout << A[2] << '\n';
	cout << A.at(2) << '\n';

	for (int i = 0; i < A.size(); i++)
		cout << A[i] << " ";
	cout << '\n';


	for (vector<int>::iterator itr = A.begin(); itr < A.end(); ++itr)
		cout << *itr << " ";
	cout << '\n';


	return 0;
}