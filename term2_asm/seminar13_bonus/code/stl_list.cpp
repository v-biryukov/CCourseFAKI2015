#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> my_list;
	my_list.push_back(1);
	my_list.push_front(8);
	my_list.push_back(1);
	my_list.push_front(4);
	my_list.push_front(7);

	auto itr = find(my_list.begin(), my_list.end(), 4);
	my_list.insert(itr, 145);



	for (auto a : my_list)
		cout << a << " ";
	cout << '\n';


	return 0;
}