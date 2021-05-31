#include <stdio.h>
// 멤버 함수 외부 작성

struct SHuman
{
	char name[12];
	int age;

	void intro();
};

void SHuman::intro()
{
	printf("이름 = %s, 나이 = %d\n", name, age);
}

int main()
{
	SHuman kim = { "김상형", 29 };
	kim.intro(); // 멤버함수는 공유되므로 this포인터를 명시해야함(생략가능)
}