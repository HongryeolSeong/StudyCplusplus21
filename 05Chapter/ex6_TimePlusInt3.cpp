#include <stdio.h>
// 객체와 기본형의 연산
// now + 1, 1 + now 둘 다 연산 가능

class Time
{
private:
	int hour, min, sec;

public:
	Time() { }
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }

	void OutTime() {
		printf("%d:%d:%d\n", hour, min, sec);
	}

	// now + 1 연산 가능
	const Time operator +(int s) const {
		Time t = *this;

		t.sec += s;

		t.min += t.sec / 60;
		t.sec %= 60;
		t.hour += t.min / 60;
		t.min %= 60;

		return t;
	}
};

// 1 + now 연산 가능
const Time operator +(int s, const Time& me) {
	return (me + s);
}

int main()
{
	Time now(11, 22, 33);
	now.OutTime();
	now = 1 + now;
	now = now + 1;
	now.OutTime();

	return 0;
}