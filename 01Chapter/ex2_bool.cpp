#include <stdio.h> // cpp에서 c가 지원됨

int main()
{
	int age = 25;
	bool isAdult = age > 19; // c에서는 bool 지원x
	if (isAdult)
	{
		puts("성인입니다.");
	}

	return 0;
}