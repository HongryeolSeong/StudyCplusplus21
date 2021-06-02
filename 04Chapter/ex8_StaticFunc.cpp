#include <stdio.h>
// static 멤버 변수 / 함수

class Simple
{
private:
	int value;
	static int count;

public:
	Simple() { count++; }
	~Simple() { count--; }
	static void InitCount() {
		count = 0;
	}
	static void Outcount() {
		printf("현재 객체 개수 = %d\n", count);
	}
};

int Simple::count;

int main()
{
	Simple::InitCount();
	Simple::Outcount();
	Simple s, * ps;
	Simple::Outcount();
	ps = new Simple;
	Simple::Outcount();
	delete ps;
	Simple::Outcount();
	printf("크기 = %d\n", sizeof(s));
}