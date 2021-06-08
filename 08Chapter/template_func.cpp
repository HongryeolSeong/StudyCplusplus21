#include <iostream>
using namespace std;
// 함수 템플릿(일반화)

template <typename T>
T ADD(T a, T b)
{


	return a + b;
}

int main()
{
	cout << ADD(10, 20) << endl;
	cout << ADD(3.14, 4.5) << endl;

	return 0;
}