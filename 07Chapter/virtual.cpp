#include <iostream>
using namespace std;
// 객체 포인터를 통한 가상 함수의 필요성 이해
// 가상 함수 : 
// 해당 포인터의 자료형으로 하위 클래스의 객체에 접근하기 위한 함수

class A
{
public:
	void AFunc() {
		cout << "A::AFunc()" << endl;
	}
};

class B : public A
{
public:
	void BFunc() {
		cout << "B::BFunc()" << endl;
	}
};

class C : public B
{
public:
	void CFunc() {
		cout << "C::CFunc()" << endl;
	}
};

int main()
{
	// 부모 -> 자식
	A* pa = new C;	// 기초 클래스 타입의 포인터가 파생 객체를 가리키고 있다. A -> C
	pa->AFunc();	// A클래스 타입 포인터이므로 C안의 상속된 A부분만 가리킬 수 있다.

	B* pb = new C;
	pb->AFunc();	// B클래스 타입 포인터로 B와 B안의 상속된 A만을 가리킬 수 있다.
	pb->BFunc();

	C* pc = new C;
	pc->AFunc();
	pc->BFunc();
	pc->CFunc();

	//C* pcc = new A;	// 자식 -> 부모이므로 불가

	return 0;
}