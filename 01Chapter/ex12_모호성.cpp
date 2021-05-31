#include <iostream>
//함수의 모호성

int func(int a)
{
	return a;
}

int func(int a, int b = 0) // 디폴트 인수 설정
{
	return a + b;
}

int main()
{
	func(10);

	return 0;
}