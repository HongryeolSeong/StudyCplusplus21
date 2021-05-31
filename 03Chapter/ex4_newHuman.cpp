#include <stdio.h>
#include <string.h>
// 객체의 동적 생성

class Human
{
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1];
		strcpy(pname, aname);
		age = aage;
		printf("== <%s> 객체 생성 ==\n", pname);
	}

	~Human() {
		printf("== <%s> 객체가 파괴 ==\n", pname);
		delete[] pname;
	}

	void intro() {
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};

int main()
{
	// 정적할당
	Human boy("김수한무거북이와두루미", 12);
	boy.intro();

	// 동적할당
	Human* leo;
	leo = new Human("레오나르도 디카프리오", 40);
	leo->intro();
	delete leo; // 해제 필수
}