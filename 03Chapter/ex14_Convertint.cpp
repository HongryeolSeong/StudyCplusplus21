#include <stdio.h>
// 변환 함수 : obj -> type
// 리턴의 타입이 없으나 리턴을 시켜준다

class Time
{
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}

	Time(int abssec) {
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	operator int() {
		return hour * 3600 + min * 60 + sec;
	}

	void OutTime() {
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 34, 56);
	int i = now;

	printf("i = %d\n", i);
}