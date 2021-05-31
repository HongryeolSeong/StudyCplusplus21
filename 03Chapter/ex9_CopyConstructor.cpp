#include <stdio.h>
#include <string.h>
// 포인터를 가진 클래스의 완전한 사본을 만들기 위한
// 깊은 복사

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
	}

	// 새로이 동적 할당 하는 복사 생성자
	// &를 안쓰는경우 무한 생성자 호출 되므로
	// &를 써서 
	Human(const Human& other) {
		pname = new char[strlen(other.pname) + 1];
		strcpy(pname, other.pname);
		age = other.age;
	}

	~Human() {
		delete[] pname;
	}

	void intro() {
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};

void printHuman(Human who) {
	who.intro();
}

int main()
{
	Human kang("강감찬", 1424);
	Human boy = kang;

	printHuman(boy);

	return 0;
}