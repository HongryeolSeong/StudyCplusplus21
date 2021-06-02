#include <stdio.h>
// mutable : 멤버를 읽을 수만 있고 변경을 못하는 규칙에 예외를 지정
//			 지정시 객체의 상수성과 상관없이 언제나 수정 가능

class Some
{
private:
	mutable int temp;	// mutable 지정

public:
	Some() { }
	void method() const { temp = 0; }
};

int main()
{
	Some s;
	s.method();

	const Some t;		// 객체 상수화
	t.method();
}