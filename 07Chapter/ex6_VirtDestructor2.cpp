#include <stdio.h>
// 가상 소멸자
// 소멸자는 항상 가상으로 선언할 것

class Base
{
private:
	char* B_buf;
public:
	Base() { B_buf = new char[10]; puts("Base 생성"); }
	virtual ~Base() { delete[] B_buf; puts("Base 파괴"); }
};

class Derived : public Base
{
private:
	int* D_buf;
public:
	Derived() { D_buf = new int[32]; puts("Derived 생성"); }
	/*virtual */~Derived() { delete[] D_buf; puts("Derived 파괴"); }
};

int main()
{
	Base* pB;

	pB = new Derived;
	delete pB;
}