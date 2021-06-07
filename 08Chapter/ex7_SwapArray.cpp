#include <stdio.h>
#include <malloc.h>
#include <memory.h>
// 템플릿 활용한 배열 swap

template <class T>
void swaparray(T* a, T* b, int num)
{
	void* t;

	t = malloc(num * sizeof(T));
	memcpy(t, a, num * sizeof(T));
	memcpy(a, b, num * sizeof(T));
	memcpy(b, t, num * sizeof(T));
	free(t);
}

int main()
{
	int a[] = { 1,2,3 }, b[] = { 4,5,6 };
	char c[] = "문자열", d[] = "string";
	//int* pa = a, * pb = b;

	/*printf("before a = %s, b = %s\n", pa, pb);
	swaparray(pa, pb, sizeof(a) / sizeof(a[0]));
	printf("after a = %s, b = %s\n", pa, pb);*/

	printf("before c = %s, d = %s\n", c, d);
	swaparray(c, d, sizeof(c) / sizeof(c[0]));
	printf("after c = %s, d = %s\n", c, d);
}