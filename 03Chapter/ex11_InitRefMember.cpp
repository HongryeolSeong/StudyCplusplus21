#include <stdio.h>
// 멤버 초기화 리스트 - 레퍼런스

class Some
{
public:
	int& total;	// 레퍼런스 이므로
	int n1, n2;
	// 멤버 초기화 리스트로 초기화 할 것
	Some(int& atotal, int on1, int on2) : total(atotal) , n1(on1), n2(on2)
	{
		//this->total = atotal;	// 대입으로 초기화x
	}
	void OutTotal() { printf("%d, %d, %d\n", total, n1, n2); }
};

int main()
{
	int value = 8;
	Some S(value, 1, 2);
	S.OutTotal();

	return 0;
}