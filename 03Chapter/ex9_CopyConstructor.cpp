#include <stdio.h>
#include <string.h>
// �����͸� ���� Ŭ������ ������ �纻�� ����� ����
// ���� ����

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

	// ������ ���� �Ҵ� �ϴ� ���� ������
	// &�� �Ⱦ��°�� ���� ������ ȣ�� �ǹǷ�
	// &�� �Ἥ 
	Human(const Human& other) {
		pname = new char[strlen(other.pname) + 1];
		strcpy(pname, other.pname);
		age = other.age;
	}

	~Human() {
		delete[] pname;
	}

	void intro() {
		printf("�̸� = %s, ���� = %d\n", pname, age);
	}
};

void printHuman(Human who) {
	who.intro();
}

int main()
{
	Human kang("������", 1424);
	Human boy = kang;

	printHuman(boy);

	return 0;
}