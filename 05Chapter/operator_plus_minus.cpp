#include <stdio.h>
// 연산자 함수
// 전역 연산자 함수

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

	/*const MyTest& operator -(const MyTest& other) const {
		MyTest res;

		res.x = this->x - other.x;
		res.y = this->y - other.y;

		return res;
	}*/

	//const MyTest& operator =(const MyTest& other) {
	//	x = other.x;
	//	y = other.y;

	//	return *this;	// 이 연산자 함수의 종료 후 리턴시 
	//					// 참조의 참조는 안되므로
	//					// 다른 오퍼레이터 리턴을 객체로 변경할 것
	//}

	// 전역 연산자 함수 사용위한 프렌드 지정
	friend MyTest operator-(const MyTest& rhs1, const MyTest& rhs2);

	// 멤버 변수 출력
	void OutValue() {
		printf("%d, %d\n", x, y);
	}
};

// 전역 연산자 함수
MyTest operator-(const MyTest& rhs1, const MyTest& rhs2) {
	MyTest res;

	res.x = rhs1.x - rhs2.x;
	res.y = rhs1.y - rhs2.y;

	return res;
}

int main()
{
	MyTest obj1(1, 2);
	MyTest obj2(3, 4);
	MyTest obj;
	obj = obj1 + obj2;			// 4, 6
	obj.OutValue();
	//obj = obj1.operator=(obj2);	// 3, 4
	//obj.OutValue();
	obj = obj2 - obj1;			// 2, 2
	obj.OutValue();

	return 0;
};