#include <stdio.h>
#include <string.h>
// 포인터의 정적 타입
// 함수 앞에 virtual 사용시 포인터가 가리키는 객체 타입에 따라 함수 호출

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

	virtual void intro() {		// 자식은 virtual 생략 가능
		printf("%d학번 %s입니다.", stunum, name);
	}

	void study() {
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}
};

int main()
{
	Human h("김사람", 10);
	Student s("이학생", 15, 1234567);
	Human* pH;

	pH = &h;
	pH->intro();
	pH = &s;
	pH->intro();	// virtual 사용전 : 정적 타입으로 Human::intro()가 호출 된다
					// virtual 사용후 : 동적 타입으로 Student::intro()가 호출 된다
}