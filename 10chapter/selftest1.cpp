#include <stdio.h>

int main()
{
	int sum = 124;
	int num = 5;
	double avg;

	avg = static_cast<double>(sum) / static_cast<double>(num);

	printf("%.2lf", avg);

	return 0;
}