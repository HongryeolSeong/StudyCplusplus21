#include <stdio.h>
// 복사 생성자

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

	// 컴파일러가 만든 복사 생성자
	/*Time(const Time &other) {
		hour = other.hour;
		min = other.min;
		sec = other.sec;
	}*/

	void OutTime() {
		printf("현재 시간은 %d:%d:%d\n", hour, min, sec);
	}
};

int main()
{
	Time now(12, 34, 56);
	Time then = now; // 이때 복사 생성자 호출
	//Tiem then(now); // 위와 동

	then.OutTime();
}