#include <stdio.h>
#include <exception>
using namespace std;
// 미처리 예외

void myterm()
{
	puts("처리되지 않은 예외 발생");
	exit(-1);
}

int main()
{
	set_terminate(myterm);
	try
	{
		throw 1;
	}
	catch (char* m)
	{

	}
}