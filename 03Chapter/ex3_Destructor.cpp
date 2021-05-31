#include <stdio.h>
#include <string.h>
// 파괴자 : 객체가 소멸될 때 자동 호출(main이 리턴될 때)

class Human
{
private:
	char* pname;
	int age;

public:
	// 생성자
	Human(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1];
		strcpy(pname, aname);
		age = aage;
		printf("%s 객체의 생성자가 호출되었습니다.\n", pname);
	}
	// 파괴자
	~Human() {
		printf("%s 객체가 파괴되었습니다.\n", pname);
		delete[] pname;
	}

	void intro() {
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};

Human boy("김수한무거북이와두루미", 12); // 전역에 선언한 경우

int main()
{
	printf("main()\n");
	//Human boy("김수한무거북이와두루미", 12);
	boy.intro();
}