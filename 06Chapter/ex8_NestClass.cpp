#include <stdio.h>
#include <string.h>
// 중첩 클래스

class Product
{
private:
	char name[64];
	char company[32];
	int price;

	class Date
	{
	protected:
		int year, month, day;
	public:
		Date(int y, int m, int d) { year = y; month = m; day = d; }
		void OutDate() { printf("%d/%d/%d", year, month, day); }
	};

	Date validto;	// 내부 클래스 객체 생성

public:
	Product(const char* aname, const char* acompany, int y, int m, int d, int aprice) :
		validto(y, m, d) {
		strcpy(name, aname);
		strcpy(company, acompany);
		price = aprice;
	}
	void OutProduct() {
		printf("이름:%s\n", name);
		printf("제소사:%s\n", company);
		printf("유효기간:");
		validto.OutDate();
		puts("");
		printf("가격:%d\n", price);
	}
};

int main()
{
	Product shrimp("새우깡", "농심", 2020, 8, 15, 900);
	shrimp.OutProduct();

	//Date now(12, 34, 56);	// Date클래스는 Product클래스의 private 멤버 타입으로
							// 선언되어 있으므로 외부에서 직접 호출 및 생성 불가
}