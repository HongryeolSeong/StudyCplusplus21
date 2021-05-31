#include <iostream>
// 멤버 함수

class/*struct*/ Human {
public:				// 클래스 정의시
	char name[20];	// 구조체 멤버는 기본적으로 public으로 설정됨
	float height;
	float weight;
	int age;
	char blood;
	void view();
};

void Human::view() // 멤버 함수 외부 작성시 범위 지정 연산자 쓸 것
{
	printf("%s %.1lf %.1lf %d %c", name, height, weight, age, blood);
}

int main()
{
	Human my = { "성홍렬", 172, 65, 27, 'A' };
	//printf("%s %.1lf %.1lf %d %c", my.name, my.height, my.weight, my.age, my.blood);
	//구조체에 포함 가능
	my.view();
	return 0;
}