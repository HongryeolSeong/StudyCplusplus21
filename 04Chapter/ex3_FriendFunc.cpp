#include <stdio.h>
// 프렌드 함수

class Date;
class Time
{
	friend void OutToday(Date&, Time&);		// friend 지정. 멤버x
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
};

class Date
{
	friend void OutToday(Date&, Time&);		// friend 지정. 멤버x
private:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
};

void OutToday(Date& d, Time& t)		// 두 객체의 모든 멤버를 읽어야 하므로 외부에 선언
{									// Time과 Date의 프렌드로 지정되어 모든 멤버에 접근 가능
	printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d입니다.\n",
		d.year, d.month, d.day, t.hour, t.min, t.sec);
}

int main()
{
	Date d(2018, 06, 29);
	Time t(12, 34, 56);
	OutToday(d, t);

	return 0;
}