#include <stdio.h>

int main()
{
	double* ar;

	ar = new double[100];

	ar[49] = 3.14;

	printf("%.2lf\n", ar[49]);

	return 0;
}