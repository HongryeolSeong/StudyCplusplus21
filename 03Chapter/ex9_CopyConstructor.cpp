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
	// 생성자
	Human(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1];
		strcpy(pname, aname);
		age = aage;
	}

	// 새로이 동적 할당 하는 복사 생성자
	// 복사생성자의 타입을 가지고 있으므로 
	// 무한반복을 피하기 위해(참조자 안쓰면 생성자 - 복사생성자순으로 무한호출) 
	// 참조자(&)연산을 사용함
	// 원래는 초깃값 없이 레퍼런스를 선언할 수 없지만, 
	// 함수형식의 인수로 사용되었으므로 초기화 안해도 됨(main이나 함수안에서 쓰려면 초기화 필요).
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