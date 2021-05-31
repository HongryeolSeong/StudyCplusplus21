#include <stdio.h>

int Add(int a, int b);
//int Add(const int a, const int b); // 사용 가능
int Add(int a, int b, int c);
double Add(double a, double b);

int main()
{
	printf("1 + 2 = %d\n", Add(1, 2));
	printf("3 + 4 + 5 = %d\n", Add(3, 4, 5));
	printf("1.414 + 2.54 = %f\n", Add(1.414, 2.54));

	return 0;
}

int Add(int a, int b)
{
	return a + b;
}

int Add(int a, int b, int c)
{
	return a + b;
}

double Add(double a, double b)
{
	return a + b;
}