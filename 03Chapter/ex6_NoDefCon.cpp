#include <stdio.h>
#include <string.h>
// 디폴트 생성자 없는경우의 에러

class Human
{
private:
	char name[12];
	int age;

public:
	/*Human() {
		strcpy(name, "이름 없음");
		age = 0;
	}*/
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}
	void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

int main()
{
	//Human momo;			// 해당하는 생성자가 없으므로
	//Human arFriend[3];	// 에러

	Human arFriend[3] = {
		{ Human("문동욱", 49)},
		{ Human("김유진", 49)},
		{ Human("박상막", 49)}
	};

	//momo.intro();
	arFriend[2].intro();
}