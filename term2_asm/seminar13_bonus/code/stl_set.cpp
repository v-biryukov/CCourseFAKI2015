#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	set<int> my_set;
	my_set.insert(1);
	my_set.insert(8);
	my_set.insert(1);
	my_set.insert(4);
	my_set.insert(7);

	auto itr = find(4);
	my_list.insert(itr, 145);



	for (auto a : my_list)
		cout << a << " ";
	cout << '\n';


	return 0;
}