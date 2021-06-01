#include <stdio.h>
// 프렌드 멤버 함수

class Time;
class Date
{
private:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
	void OutToday(Time& t);

	// Time의 멤버를 참조해야하므로 클래스 내 선언 불가
	/*void OutToday(Time& t)
	{
		printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d입니다.\n",
			year, month, day, t.hour, t.min, t.sec);
	}*/
};

class Time
{
	// Date의 함수 OutToday에서 Time의 멤버 접근 허용
	friend void Date::OutToday(Time& t);
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
};

void Date::OutToday(Time& t)
{
	printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d입니다.\n",
		year, month, day, t.hour, t.min, t.sec);
}

int main()
{
	Date d(2018, 06, 29);
	Time t(12, 34, 56);
	d.OutToday(t);
}