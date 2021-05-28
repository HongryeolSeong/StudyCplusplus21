#include <stdio.h>

int GetSum(int from, int to, int step = 1, int base = 0);
// 디폴트 인수 생성, 디폴트 인수는 중간에 생성 x -> 무조건 뒤에서 부터 생성 할 것
int main()
{
	printf("%d\n", GetSum(1, 10));
	printf("%d\n", GetSum(1, 10, 2));
	printf("%d\n", GetSum(1, 10, 2, 10));

	return 0;
}

// 디폴트 인수는 정의부 지정x -> 원형 지정
int GetSum(int from, int to, int step /*= 1*/, int base /*= 0*/)
{
	int sum = base;
	for (int i = from; i <= to; i += step)
	{
		sum += i;
	}
	return sum;
}