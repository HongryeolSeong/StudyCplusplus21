#include <stdio.h>
// 인수의 타입모호시 오류발생 -> 명시적 인수 사용할 것

template <typename T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

int main()
{
	int a = max<int>(1, 2);
	double b = max(1.1, 2.2);
	//int c = max(2, 3.14);		// 타입이 모호하므로 오류
	 
	printf("a = %d\n", a);
	printf("b = %.1lf\n", b);
	//printf("c = %d\n", c);
}