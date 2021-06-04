#include <stdio.h>
#include <string.h>
// 가상 함수의 활용 - 재정의
// 앞으로 재정의 될 것을 예상하여 부모에 가상 함수 지정
// 부모의 가상 함수 본체가 공백인 것 -> 순수 가상 함수

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
	void eat() {
		puts("냠냠냠");
	}
	virtual void intro() {
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
	void intro() {
		printf("%d학번 %s입니다.\n", stunum, name);
	}
};

int main()
{
	Human h("김사람", 10);
	Student s("이학생", 15, 1234567);
	Human* pH;

	pH = &h;
	pH->intro();
	pH->eat();

	pH = &s;
	pH->intro();
	pH->eat();
}