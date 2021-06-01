#include <stdio.h>
// 변환 생성자 : type -> obj

class Time
{
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
	// 변환 생성자
	// 임시객체 생성 후 변환하여 멤버에 대입
	explicit Time(int abssec)	// 명시적 변환만을 허용하기 위해 explicit사용
	{
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	void OutTime()
	{
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

void printTime(Time when)
{
	when.OutTime();
}

int main()
{
	Time noon(40000);	// 생성자를 명시적 호출
	noon.OutTime();
	/*Time now = 60000;	// 타입 변환을 통한 생성자 호출
	now.OutTime();		// -> 모호성이 있는경우 explicit가 호출을 막아줌
	now = 70000;
	now.OutTime();

	printTime(80000);*/

	return 0;
}