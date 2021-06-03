#include <stdio.h>
// 객체와 기본형의 연산

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

int main()
{
	Time now(11, 22, 33);
	now.OutTime();
	now = now + 1;
	//now = 1 + now;	// 불가 : 1의 클래스인 int에 Time 객체를 받는 연산자 함수가 없다.
						//		  int는 임의로 확장 불가 -> ex5
	now.OutTime();

	return 0;
}