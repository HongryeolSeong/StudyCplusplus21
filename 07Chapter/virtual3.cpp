#include <iostream>
using namespace std;
// 가상 소멸자

class CTest
{
private:
	int num;

public:
	CTest(int anum)
	{
		num = anum;
		cout << num << " CTest constructor" << endl;
	}
	virtual ~CTest() {
		cout << num << " CTest destructor" << endl;
	}
	virtual void func() {
		cout << "CTest function()" << endl;
	}
};

class CTestSub : public CTest
{
private:
	int subN;

public:
	CTestSub(int anum, int asubN) : CTest(anum)
	{
		subN = asubN;
		cout << subN << " CTestSub constructor" << endl;
	}
	~CTestSub() {
		cout << subN << " CTestSub destructor" << endl;
	}
	void func() {
		cout << "CTestSub function()" << endl;
	}
};

int main()
{
	CTest b(10);
	b.func();

	CTestSub d(10, 20);
	d.func();

	CTest* pb = new CTestSub(30, 33); // 추상자료형으로 자식객체를 가리키게 한다.
	pb->func();

	delete pb;	// 메모리 동적할당 받은 sub클래스의 소멸자가 생성 안됨
				// 부모 소멸자에 virtual 붙일시 파생 클래스의 소멸자 생성

	return 0;
}