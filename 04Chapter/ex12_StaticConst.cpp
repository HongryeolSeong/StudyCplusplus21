#include <stdio.h>
// 상수 + static 멤버

class MathCalc
{
private:
	static const double pie;			// pie 상수화 + static

public:
	MathCalc() { }
	void DoCalc(double r) {
		printf("반지름 %.2f인 원의 둘레 = %.2f\n", r, r * 2 * pie);
	}
};

const double MathCalc::pie = 3.1416;	// pie는 static 변수이므로 클래스 밖에서 초기화

int main()
{
	MathCalc m;
	m.DoCalc(5);
}