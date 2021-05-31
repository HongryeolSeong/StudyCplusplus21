#include <stdio.h>
// 액세스 지정

struct SHuman
{						// 캡슐화
private:				// 은닉
	char name[12];
	int age;

public:
	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	SHuman kim;
	//kim.age = 286; //private 변수이므로 불가
	kim.intro();
}