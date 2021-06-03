#include <stdio.h>
#include <string.h>

class Human
{
private:
	char* name;
	int age;

public:
	Human() { }

	// 인수 2개인 생성자
	Human(const char *aname, int aage) {
		name = new char[strlen(aname) + 1];
		strcpy(name, aname);
		age = aage;
		printf("나이가 %d인 객체가 생성되었습니다.\n", age);
	}

	// 복사 생성자
	Human(const Human& other) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;
		printf("복사 생성자가 호출되었습니다.\n");
	}

	// 소멸자
	~Human() {
		delete[] name;
		printf("나이가 %d인 객체가 소멸되었습니다.\n", age);
	}

	// 연산자 함수(연산자 오버로딩)
	const Human& operator =(const Human& other) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;

		printf("오퍼레이터 =이 실행되었습니다.\n");

		return *this;
	}

	void PrintHuman() {
		printf("이름 : %s, 나이 : %d\n\n", name, age);
	}
};


int main()
{
	Human h1("성홍렬", 27);
	h1.PrintHuman();
	Human h2("김영훈", 25);
	h2.PrintHuman();

	Human h3(h1);
	h3.PrintHuman();

	Human Xman;
	Xman = h2;
	Xman.PrintHuman();

	return 0;
}