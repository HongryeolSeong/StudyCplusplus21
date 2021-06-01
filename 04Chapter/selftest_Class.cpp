#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class Human
{
private:
	char pname[12];
	int age;

public:
	Human(const char* n, int a) {
		SetName(n);
		SetAge(a);
	}

	void SetName(const char* n) {
		if (strlen(n) < 12)
		{
			strcpy(pname, n);
		}
		else if (strlen(n) > 12)
		{
			strcpy(pname, "");
		}
	}

	void SetAge(int a) {
		if (a >= 0 && a <= 120)
		{
			age = a;
		}
		else
		{
			age = 0;
		}
	}

	void Output() {
		printf("이름은 %s이고 나이는 %d살입니다.\n", pname, age);
	}
};

int main()
{
	char temp[100];

	Human person("홍길동", 27);
	person.Output();

	cin >> temp;
	person.SetName(temp);
	person.Output();
	person.SetAge(180);
	person.Output();

	return 0;
}