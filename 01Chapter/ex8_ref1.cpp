#include <stdio.h>

int main()
{
	int i = 3;
	int& ri = i; // 레퍼런스 선언시 초기화 필수
	int* pi = &i;
	//int* pri = &ri;			// 가능
	//int&* pri = &ri;			// 불가
	//int& rri = ri;			// 불가
	//int& ra[2] = { i, j };	// 레퍼런스 배열 불가

	printf("i = %d, ri = %d, pi = %x\n", i, ri, pi);
	ri++;
	printf("i = %d, ri = %d, pi = %d\n", i, ri, *pi); // 동일한 데이터
	printf("i번지 = %x, ri번지 = %x, pi번지 = %x\n", &i, &ri, &pi); // 동일한 주소
}