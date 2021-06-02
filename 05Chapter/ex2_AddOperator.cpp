#include <stdio.h>
// 객체 더하기

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

	// 원래는 레퍼런스가 리턴 돼야함
	const Time operator +(const Time& other) const {
		Time t;								//이 const는 t1의 멤버들을 상수화 시킨다.
		t.sec = sec + other.sec;
		t.min = min + other.min;
		t.hour = hour + other.hour;

		t.min += t.sec / 60;
		t.sec %= 60;
		t.hour += t.min / 60;
		t.min %= 60;
		return t; // 반환과 동시에 상수화
	}
};

int main()
{
	Time t1(1, 10, 30);
	Time t2(2, 20, 40);
	Time t3;

	//t3 = t1.operator +(t2);
	t3 = t1 + t2;

	return 0;
}