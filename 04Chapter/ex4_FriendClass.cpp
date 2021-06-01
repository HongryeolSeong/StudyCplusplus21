#include <stdio.h>
// 프렌드 클래스

class Date;
class Time
{
	friend class Date;		// Date를 Time의 친구로 지정(반대는 안됨) 
private:					// Date -> Time 접근 o
	int hour, min, sec;		// Time -> Date 접근 x
public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	// Time에서 Date의 멤버에 접근 불가하므로 함수 사용 불가
	//void OutToday(Date& d) {
	//	printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d입니다.\n",
	//		d.year, d.month, d.day, hour, min, sec);
	//}
};

class Date
{
private:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
	void OutToday(Time& t) {
		printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d입니다.\n",
			year, month, day, t.hour, t.min, t.sec);
	}
};

int main()
{
	Date d(2018, 06, 29);
	Time t(12, 34, 56);
	d.OutToday(t);
}