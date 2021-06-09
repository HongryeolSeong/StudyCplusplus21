#include <iostream>
using namespace std;

class Base {
private:
	int data;
public:
	Base() {};

	~Base() {};

	void setData(int adata)
	{
		data = adata;
	}

	int getData()
	{
		return data;
	}
};

class Derived : public Base {
public:
	void setData(int adata) {
		if (adata > 0) adata = 0;
		Base::setData(adata);
	}
	void printData() {
		cout << "printData() : " << getData() << endl;
	}
};

int main()
{
	Base* pb = new Derived;
	Derived* pd = NULL;

	pb->setData(10);	// 기초 클래스의 setData호출
	pd = static_cast<Derived*>(pb);	// pb의 타입을 Derived으로 바꾼다
	pd->setData(20);	// 파생 클래스의 setData호출
	pd->printData();

	return 0;
}