#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;
	vector<int> v1 = { 1, 2, 3, 4, 5 };
	vector<int> v2[5];

	v.push_back(10);

	vector<int> ::iterator iter = v.begin();
	iter = v.insert(iter, 2);

	v.pop_back();
	v.erase(v.begin() + 10);
	v.clear();

	return 0;
}
