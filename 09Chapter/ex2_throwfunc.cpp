#include <stdio.h>
// �Լ��� ���� ó��

void divide(int a, int d)
{
	if (d == 0) throw "0���δ� ���� �� �����ϴ�.";
	printf("������ ��� = %d�Դϴ�.\n", a / d);
}

int main()
{
	try
	{
		divide(10, 0);	// ���� �߻��� �Լ����� throw ó��
	}
	catch (const char *message)
	{
		puts(message);
	}

//	divide(2, 0);		// trycatch�� �����Ƿ� ���α׷� �ߴ�

	divide(10, 5);
}