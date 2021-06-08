#include <stdio.h>
// trycatch로 예외 처리

int main()
{
	int a, b;

	while (1)
	{
		try
		{
			printf("나누어질 수를 입력하시오 : ");
			scanf("%d", &a);
			if (a < 0) throw a;	// a를 들고 catch로 점프
			printf("나누는 수를 입력하시오 : ");
			scanf("%d", &b);
			if (b == 0) throw "0으로는 나눌 수 없습니다.";
			printf("나누기 결과는 %d입니다.\n", a / b);
		}
		catch (int a)
		{
			printf("%d는 음수이므로 나누기 거부\n", a);
		}
		catch (const char* message)
		{
			puts(message);
		}
	}
	
	
}