#include "cursor.h"
#include <iostream>
using namespace std;
// 클래스 템플릿

template <typename T>	// 클래스 템플릿이므로
class PosValue			// PosValue라는 이름만으로는 객체 생성 불가
{						// <타입>을 붙여서 객체 생성할 것
private:
	int x, y;
	T value;
public:
	PosValue(int ax, int ay, T av) : x(ax), y(ay), value(av) {}
	void outvalue() {
		gotoxy(x, y);
		cout << value << endl;
	}
};

int main()
{
	PosValue<int> iv(10, 10, 2);		// <int>로 명시적 표시할 것
										// <>안 타입에 따라 메모리 할당
	PosValue<char> cv(25, 5, 'C');
	PosValue<double> dv(30, 15, 3.14);
	iv.outvalue();
	cv.outvalue();
	dv.outvalue();
}