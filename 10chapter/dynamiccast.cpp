#include <iostream>

class A {
public:
	virtual void test() {
		printf("A::test()\n");
	}
};

class B : public A {
public:
	virtual void test() {
		printf("B::test()\n");
	}
	void test2() {
		printf("B::test2()\n");
	}
};

class C : public B {
public:
	virtual void test() {
		printf("C::test()\n");
	}
	void test2() {
		printf("C::test2()\n");
	}
};

void GlobalFunc(A& a) {
	try
	{
		C& c = dynamic_cast<C&>(a);
		printf("GlobalFunc()\n");
	}
	catch (std::bad_cast)
	{
		printf("casting Error\n");
	}
}

int main()
{
	A* pa = new C;
	A* paa = new B;
	pa->test();

	B* pb = dynamic_cast<B*>(pa);
	if (pb) pb->test2();

	C* pc = dynamic_cast<C*>(paa);	// C가 B를 가리키는 꼴 : 업캐스팅 --> 오류
	if (pc) pc->test2();			// 자식 포인터로 부모 객체를 가리키는 형태

	C c;
	GlobalFunc(c);

	B b;							// 위와 동일한 오류
	GlobalFunc(b);

	return 0;
}