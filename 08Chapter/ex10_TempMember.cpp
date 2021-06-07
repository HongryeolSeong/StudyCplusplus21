#include <stdio.h>
// 템플릿 멤버 함수

//template <typename T>		// 요기 선언시 클래스 템플릿 선언
class Util
{
public:
	template <typename T>
	void swap(T& a, T& b)
	{
		T t;
		t = a; a = b; b = t;
	}
};

int main()
{
	//Util<int> u;				// 클래스 템플릿 사용시
	//Util<double> u;				// 클래스 템플릿 사용시
	//Util<char> u;				// 클래스 템플릿 사용시
	Util u;
	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	char e = 'e', f = 'f';

	u.swap(a, b);
	u.swap(c, d);
	u.swap(e, f);
	printf("a = %d, b = %d\n", a, b);
	printf("c = %f, d = %f\n", c, d);
	printf("e = %c, f = %c\n", e, f);
}