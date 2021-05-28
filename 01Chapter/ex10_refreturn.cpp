#include <stdio.h>

int ar[] = { 1, 2, 3, 4, 5 };

int& GetAr(int i)
{
	return ar[i]; // 레퍼런스를 반환
}

int main()
{
	//int& ra = 10;	// 상수에 대한 레퍼런스 생성 불가

	GetAr(3) = 6;	// 레퍼런스는 lvalue에 대해서만 생성 가능
	printf("ar[3] = %d\n", ar[3]);

	return 0;
}
