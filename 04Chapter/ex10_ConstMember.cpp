#include <stdio.h>
// 상수 멤버

class MathCalc
{
private:
	const double pie; // pie 상수화

public:
	MathCalc(double apie) : pie(apie) { } // 상수 pie 초기화
	void DoCalc(double r) {
		printf("반지름 %.2f인 원의 둘레 = %.2f\n", r, r * 2 * pie);
	}
};

int main()
{
	MathCalc m(3.1416); // 객체 생성시 상수 pie를 3.1416으로 초기화
	m.DoCalc(5);
}