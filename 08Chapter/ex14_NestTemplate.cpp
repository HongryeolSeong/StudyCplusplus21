#include "cursor.h"
#include <iostream>
using namespace std;
// 템플릿 중첩

template <typename T>
class PosValue
{
private:
	int x, y;
	T value;
public:
	PosValue() : x(0), y(0), value(0) { }
	PosValue(int ax, int ay, T av) : x(ax), y(ay), value(av) { }
	void outvalue() {
		gotoxy(x, y);
		cout << value << endl;
	}
};

template <typename T>
class Wrapper
{
private:
	T member;
public:
	void set(T v) { member = v; }
	T get() { return member; }
};

int main()
{
	Wrapper<PosValue<char> > wrap;	// wrap의 타입을 PosValue<char>로 하여 객체 생성
				// 선언시 위 꺽쇠는 띄어서 쓸 것(시프트 연산자로 처리 가능성 있음)
	wrap.set(PosValue<char>(10, 10, 'a'));
	PosValue<char> pc = wrap.get();
	pc.outvalue();
}