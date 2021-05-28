#include <stdio.h>

int main()
{
	enum origin { EAST, WEST, SOUTH, NORYH };
	//enum origin mark = WEST; // c방식
	origin mark = WEST; // cpp에서는 태크 생략 가능
	printf("%d 방향\n", mark);

	typedef struct shuman
	{
		char name[12];
		int age;
		double height;
	} SHuman;

	//struct SHuman kim = { "김상형", 29, 181.4 }; // c방식
	SHuman kim = { "김상형", 29, 181.4 }; // cpp
	printf("이름 = %s, 나이 = %d\n", kim.name, kim.age);

	return 0;
}