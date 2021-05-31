#include <stdio.h>
#include <string.h>
// 생성자

class Human
{
private:
	char name[12];
	int age;

public:
	// 생성자
	/*Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}*/
	Human(const char* name, int age) {			// 위와 동
		strcpy(this->name, name);
		this->age = age;
	}
	//Human(const char* name, int age) {		// 위와 동
	//	strcpy(Human::name, name);				// 잘 사용 안한다
	//	Human::age = age;
	//}
	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	Human kim("김상형", 29);
	kim.intro();
}