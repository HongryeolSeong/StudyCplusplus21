#include <stdio.h>
#include <malloc.h>
#include <string.h>

void InputNameRef(char*& Name)
{
	Name = (char*)malloc(32);
	strcpy(Name, "kim sang hyung");
}

int main()
{
	char* Name;

	InputNameRef(Name); // Name이 실인수로 넘겨지는지 레퍼런스로 넘겨는지 모르니
						// Ref로 표시해줄 것  
	printf("이름은 %s입니다.\n", Name);
	free(Name);
}