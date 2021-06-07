#include <stdio.h>
// 명시적 인수

template <typename T>
T cast(int s)
{
	return (T)s;		// int타입인 s를 T타입으로 캐스팅 후 리턴
}

int main()
{
	unsigned u = cast<unsigned>(1234);	// <>로 템플릿 인수의 타입을 밝힌다
	double d = cast<double>(5678);

	printf("u = %d, d = %f\n", u, d);
}