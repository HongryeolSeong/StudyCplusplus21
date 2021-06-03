#include <stdio.h>
#include <string.h>
// 멤버 함수 재정의

class Human
{
protected:
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}

	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

class Student : public Human
{
protected:
	int stunum;

public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {
		stunum = astunum;
	}

	void study() {
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}

	// 부모의 intro 재정의
	void intro() {
		printf("%d학번 %s입니다.\n", stunum, name);
	}
};

int main()
{
	Human kim("김상형", 29);
	kim.intro();
	Student han("김한결", 15, 123456);
	//han.intro();		// 자식 intro 호출
	han.Human::intro();	// 부모 intro 호출
}