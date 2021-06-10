#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v = { 10, 20, 30, 40, 50 };
	for (auto i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}

	cout << endl;

	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << ' ';
	}

	cout << endl;

	for (auto i = v.begin(); i != v.end(); i++)
	{
		cout << *i << ' ';
	}

	return 0;
}