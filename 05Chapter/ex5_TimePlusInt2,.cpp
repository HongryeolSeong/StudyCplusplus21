#include <stdio.h>
// 객체와 기본형의 연산
// 1 + now 연산 불가 해결

class Time
{
	friend const Time operator +(int s, const Time& me);
private:
	int hour, min, sec;

public:
	Time() { }
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutTime() {
		printf("%d:%d:%d\n", hour, min, sec);
	}
};

// 1 + now 연산 가능한 연산자 함수
const Time operator +(int s, const Time& me) {
	Time t = me;

	t.sec += s;

	t.min += t.sec / 60;
	t.sec %= 60;
	t.hour += t.min / 60;
	t.min %= 60;

	return t;
}

int main()
{
	Time now(11, 22, 33);
	now.OutTime();
	now = 1 + now;
	//now = now + 1;	// 불가 : operator +(int, Time) 형태이므로 불가
						//		  -> ex6으로 해결
	now.OutTime();
}