#include <stdio.h>

int main()
{
	int* pi, *pj;

	pi = new int;		// 동적 할당 + 생성자호출(초기화) 수행
	pj = new int(10);	// 포인터 = new 타입[(초깃값)];
	
	*pi = 123;

	printf("*pi = %d\n", *pi);
	printf("*pj = %d\n", *pj);

	delete pi;
	delete pj;
}