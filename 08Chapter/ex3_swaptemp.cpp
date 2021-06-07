#include <stdio.h>
// 함수 템플릿
// 템플릿 = 붕어빵틀 -> 사용안할시 메모리사용 x

template<typename T>
void swap(T& a, T& b)
{
	T t;
	t = a; a = b; b = t;
}

int main()
{
	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	char e = 'e', f = 'f';

	swap(a, b);
	swap(c, d);
	swap(e, f);
	printf("a = %d, b = %d\n", a, b);
	printf("c = %f, d = %f\n", c, d);
	printf("e = %c, f = %c\n", e, f);
}