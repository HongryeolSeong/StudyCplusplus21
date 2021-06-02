#include <iostream>
// static 멤버 변수 / 함수

class StaticTest {
	static int a;				// static 멤버 변수
	int b;
public:
	StaticTest();
	static void setData(int);	// static 멤버 함수는 static 멤버 변수에 사용한다.
	void getData();
};

int StaticTest::a = 10;			// static 멤버 변수 초기화

StaticTest::StaticTest()
{
	b = 20;						//this->b = 20;가 정확한 식
}

void StaticTest::getData()
{
	printf("a : %d, b : %d\n", a, b);
}

void StaticTest::setData(int aa)
{
	a = aa;						//this->a = a;; ---> X
}								//a는 static이므로 객체내 변수가 아니다.

int main()
{
	StaticTest s1;
	s1.getData();
	StaticTest s2;
	s2.getData();

	s1.setData(30);
	s1.getData();				// s1의 a는 30
	s2.getData();				// s2의 a도 30이다.

	StaticTest::setData(77);	// a는 공유되므로 s1, s2 둘 다 a가 바뀐다.
	s1.getData();
	s2.getData();

	return 0;
}