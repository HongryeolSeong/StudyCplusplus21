#include <stdio.h>
// 멤버 초기화 리스트 - 상수

class Some
{
public:
	const int total;						// 상수이므로
	Some(int atotal) : total(atotal) {}		// 이런식으로 초기화해야함
	//some(int atotal) {					// 대입연산으로 초기화하면 안됨
	//	total = atotal;
	//}
	void OutTotal() { printf("%d\n", total); }
};

int main()
{
	Some S(5);
	S.OutTotal();

	return 0;
}