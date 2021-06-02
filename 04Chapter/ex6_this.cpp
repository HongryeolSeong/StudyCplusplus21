#include <stdio.h>
// this 포인터 : 번지가 자기 자신으로 고정된 포인터 상수

class Simple
{
private:
	int value;

public:
	Simple(int avalue) : value(avalue) { }	// 멤버 초기화 리스트
	void OutValue() {
		printf("value = %d\n", value);
	}
};

int main()
{
	Simple A(1), B(2);
	A.OutValue();
	B.OutValue();

	return 0;
}