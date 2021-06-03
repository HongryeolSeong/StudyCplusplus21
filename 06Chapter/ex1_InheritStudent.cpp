#include <stdio.h>
#include <string.h>
// 상속 : 대부분 public으로 상속받는다
// 1. 파생 클래스의 생성자 호출
// 2. 부모 클래스의 생성자 호출 및 실행
// 3. 파생 클래스의 생성자 실행

class Human
{
private:
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
private:
	int stunum;

public:												// 부모클래스의 인수가 2개인 생성자 호출
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {
		stunum = astunum;
	}

	void study() {
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}

	// 불가 : 부모의 멤버가 private이므로
	/*void report() {
		printf("이름 : %s, 학번 : %d 보고서 제출합니다.\n", name, stunum);
	}*/
};

int main()
{
	Human kim("김상형", 29);
	kim.intro();
	Student han("김한결", 15, 123456);
	han.intro();
	han.study();
}