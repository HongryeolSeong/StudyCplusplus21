#include <iostream>
// 정적 멤버 변수 : 객체와 논리적 연결된 변수. 객체내에 포함 x
//					외부에서 초기화 할 것

class StaticTest {
public:
	int a;
	static int b;		// static 멤버 변수 선언
	StaticTest() {
		a = 10;
		//b = 20; // 불가
		b++;			// 객체 생성마다 +1
	}
	void getData() {
		printf("a : %d, b: %d\n", a, b);
	}
};

int StaticTest::b = 20;	// static 멤버 변수 초기화
						// 외부에서 할 것
						// 멤버 변수가 소속된 클래스를 표시 할 것

int main()
{
	StaticTest s1;
	s1.getData();
	StaticTest s2;
	s2.getData();

	return 0;
}