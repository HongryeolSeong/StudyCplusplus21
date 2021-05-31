#include <stdio.h>
// 클래스의 예2

class Date
{
private:
	int year, month, day;

public:
	void SetDate(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}

	void OutDate() {
		printf("오늘 날짜는 %d년 %d월 %d일입니다.\n", year, month, day);
	}
};

int main()
{
	Date today;

	today.SetDate(2021, 05, 31);
	today.OutDate();

	return 0;
}