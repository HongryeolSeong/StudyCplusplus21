#include <stdio.h>
#include <string.h>
// 포함을 통한 클래스 재활용 : HAS A
// 보통 public 상속은 IS A

class Date
{
protected:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
	void OutDate() { printf("%d/%d/%d", year, month, day); }
};

class Product
{
private:
	char name[64];
	char company[32];
	Date validto;		// Date클래스의 객체 validto를 Product에 멤버로서 포함
	int price;
public:
	Product(const char* aname, const char* acompany, int y, int m, int d, int aprice) : 
		validto(y, m, d) {
	// 객체명을 써준다. 멤버이므로.
		strcpy(name, aname);
		strcpy(company, acompany);
		price = aprice;
	}
	void OutProduct() {
		printf("이름:%s\n", name);
		printf("제조사:%s\n", company);
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
}