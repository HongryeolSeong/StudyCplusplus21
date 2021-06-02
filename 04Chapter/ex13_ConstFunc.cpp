#include <stdio.h>
// 상수 멤버 함수 : 멤버를 읽을 수만 있고 변경 불가

class Time
{
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) {
		SetTime(h, m, s);
	}

	void SetTime(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}

	void OutTime() const {	// 멤버 함수를 상수화
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 34, 56);
	now.SetTime(11, 22, 33);
	now.OutTime();

	const Time meeting(16, 00, 00);		// 상수로 객체 선언 -> 이후 값 변경 불가
	//meeting.SetTime(11, 11, 11);		// 불가
	meeting.OutTime();
}