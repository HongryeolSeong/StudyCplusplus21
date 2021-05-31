#include <stdio.h>

void sub(int a) { printf("int: %d\n", a); }
void sub(int *a) { printf("pointer: %p\n", a); }

int main()
{
	int i = 1234, *pi = &i;

	sub(i);
	sub(pi);
	sub(NULL);	// 정수 0, 널포인터 둘 다 가능하기에 모호성이 있다.
				// 컴파일러는 정수 0으로 본다.
				// sub((int*)NULL)로 캐스팅할 시 널포인터로 호출됨
}