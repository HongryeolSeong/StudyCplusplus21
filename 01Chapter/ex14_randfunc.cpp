#include <stdio.h>
#include <stdlib.h>

//int randfunc(int n)
//{
//	return rand() % n;
//}

inline int randfunc(int n)	// 인라인 함수
{							// 함수 호출시 분기x -> 더 빠르게 함수 호출
	return rand() % n;		// 메인에 함수 본체를 새김
}

int main()
{
	int i, j, k;
	i = randfunc(10);
	j = randfunc(100);
	k = randfunc(50);
	printf("난수 = %d, %d, %d\n", i, j, k);
}