#include <iostream>
using namespace std;
// ���� �ǰ��� ����

void TestFunc1()
{
	cout << "TestFunc1() START" << endl;
//	throw 0;
	cout << "TestFunc1() END" << endl;
}

void TestFunc2()
{
	cout << "TestFunc2() START" << endl;
//	TestFunc1();
	throw 0;
	cout << "TEstFunc2() END" << endl;
}

void TestFunc3()
{
	cout << "TestFunc3() START" << endl;
	TestFunc2();
	cout << "TEstFunc3() END" << endl;
}

int main()
{
	try
	{
		TestFunc3();
	}
	catch (...)	// ... : ��� Ÿ���� �� �޴´�.
	{
		cout << "Exception Handling" << endl;
	}
	TestFunc1();

	return 0;
}