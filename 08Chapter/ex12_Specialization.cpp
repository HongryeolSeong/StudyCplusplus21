#include <stdio.h>
// 함수 특수화 : 특정 타입에 대해 약간 다르게 동작하는 함수를 정의
// <-> 일반화

template <class T>
void swap(T& a, T& b)
{
	T t;
	t = a; a = b; b = t;
}

template <> void swap<double>(double& a, double& b)
{
	int i, j;

	i = (int)a;
	j = (int)b;
	a = a - i + j;
	b = b - j + i;
}

int main()
{
	double a = 1.2, b = 3.4;
	printf("a = %g, b = %g\n", a, b);
	swap(a, b);
	printf("a = %g, b = %g\n", a, b);

	return 0;
}