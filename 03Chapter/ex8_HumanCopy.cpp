#include <stdio.h>
#include <string.h>
// 동적 할당 메모리의 얕은 복사로 인한
// 사본 생성 에러
// 원본과 사본의 포인터가 같은 번지를 가르키므로
// 변경 및 파괴시 문제가 된다.

class Human
{
private:
	char* pname;
	int age;

public:
	Human(const char* aname, int aage) {
		pname = new char[strlen(aname) + 1]; // 동적 할당
		strcpy(pname, aname);
		age = aage;
	}

	~Human() {
		delete[] pname;
	}

	void intro() {
		printf("이름 = %s, 나이 = %d\n", pname, age);
	}
};

int main()
{
	Human kang("강감찬", 1424);
	Human boy = kang;

	boy.intro();
}