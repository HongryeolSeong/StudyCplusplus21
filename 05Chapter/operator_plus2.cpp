#include <stdio.h>

class MyTest
{
private:
	int x, y;

public:
	MyTest(int ax = 0, int ay = 0) 
	{ 
		x = ax;
		y = ay;
		printf("인수 2개짜리 생성자!!\n");
	}

	MyTest(MyTest& other) : x(other.x), y(other.y)
	{
		printf("복사 생성자 호출!!\n");
	}

	const MyTest& operator +(const MyTest& other) const {
		MyTest res;

		res.x = this->x + other.x;
		res.y = this->y + other.y;

		return res; // 임시 객체 생성 -> 복사 생성자가 호출
					// 참조를 리턴시 복사 생성자 호출x
					// 출력(반환)은 참조자 타입으로 할 것
	}

	void OutValue() {
		printf("%d, %d\n", x, y);
	}
};

int main()
{
	MyTest obj1(1, 2);
	MyTest obj2(3, 4);
	MyTest obj;
	obj = obj1 + obj2;
	obj.OutValue();

	return 0;
};