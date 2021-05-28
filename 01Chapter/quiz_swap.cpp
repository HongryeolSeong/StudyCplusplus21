#include <stdio.h>

void swap(int& ra, int& rb);
void swap1(int a, int b);

int main()
{
	int a = 1;
	int b = 2;
	int& ra = a;
	int& rb = b;


	swap(a, b); // 실인수를 호출해야 한다.
	//swap1(a, b);


	return 0;
}

void swap(int& ra, int& rb)
{
	int temp;

	printf("%d %d\n", ra, rb);

	temp = ra;
	ra = rb;
	rb = temp;

	printf("%d %d\n", ra, rb);
}

void swap1(int a, int b)
{
	int temp;

	printf("%d %d\n", a, b);

	temp = a;
	a = b;
	b = temp;

	printf("%d %d\n", a, b);
}