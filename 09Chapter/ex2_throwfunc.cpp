#include <stdio.h>
// 함수내 예외 처리

void divide(int a, int d)
{
	if (d == 0) throw "0으로는 나눌 수 없습니다.";
	printf("나누기 결과 = %d입니다.\n", a / d);
}

int main()
{
	try
	{
		divide(10, 0);	// 예외 발생시 함수안의 throw 처리
	}
	catch (const char *message)
	{
		puts(message);
	}

//	divide(2, 0);		// trycatch가 없으므로 프로그램 중단

	divide(10, 5);
}