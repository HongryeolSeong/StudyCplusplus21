#include <iostream>

class CTest {
private:
	int m_num;
	int* ptr;
public:
	// 디폴트 생성자
	CTest() {
		printf("디폴트 생성자 호출\n");
	}
	// 인수를 하나 가지는 생성자(변환 생성자)
	CTest(int num) {
		m_num = num;
		printf("생성자 호출 : %d\n", m_num);
	}
	// 인수 두 개를 가지는 생성자
	CTest(int num, int* ptr) {
		this->m_num = num;
		this->ptr = new int;	// 동적 할당
		this->ptr = ptr;
		printf("인수 2개 생성자 호출 : %d, %p\n", m_num, ptr);
	}
	// 깊은 복사를 하는 복사 생성자
	CTest(CTest& other) {
		this->m_num = other.m_num;
		this->ptr = new int;	// 동적 할당
		this->ptr = other.ptr;
		printf("복사 생성자 호출 : %d, %p\n", m_num, ptr);
	}
	// 얕은 복사 생성자
	/*CTest(CTest &other) {
		this->m_num = other.m_num;
		printf("복사 생성자 호출 : %d\n", m_num);
	}*/
	// 소멸자
	~CTest() {
		printf("소멸자 호출 : %d\n", m_num);
		delete ptr;				// 동적 할당한 경우 소멸자에서 해제시킨다.
	}
	void getData() {
		printf("%d\n", m_num);
	}
};

int main()
{
	// 기본 자료형
	int a = 10;
	int b(20);	//cpp에서 사용되는 문법
	int c(a);

	printf("%d, %d, %d\n", a, b, c);

	// 사용자 자료형
	CTest c1(100);	// 인수 한 개의 생성자 호출, 생성자 없을시 오류
	CTest c2;		// 디폴트 생성자 호출, 생성자 있을시 디폴트 생성자 못쓰기때문에 오류
	CTest c3(c1);	// 복사 생성자 호출(얕은 복사) - 주소를 복사함(참조를 전달받기 때문에)
	CTest c4(50, nullptr);

	//c1.getData();
	//c2.getData(); // 쓰레기값
	//c3.getData();
	
	return 0;
}