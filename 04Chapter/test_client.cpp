#include <stdio.h>
#include <string.h>

class CMember
{
private:
	char *name;
	char *pnum;
	char *address;
	static int cnt;

public:
	CMember() { cnt++; }
	~CMember() { cnt--; }
	static void InitCount() {
		cnt = 0;
	}
	static void Outcount() {
		printf("현재 회원 수 = %d\n", cnt);
	}
	void setData(const char *aname, const char* apnum, const char *aaddress)
	{
		name = new char[strlen(aname) + 1];
		strcpy(name, aname);
		pnum = new char[strlen(apnum) + 1];
		strcpy(pnum, apnum);
		address = new char[strlen(aaddress) + 1];
		strcpy(address, aaddress);
	}
	void getData() {
		printf("이름 : %s, 전화 번호 : %s, 주소 : %s\n", name, pnum, address);
	}
};

int CMember::cnt = 0;		// static 멤버 변수 cnt 초기화

int main()
{
	CMember::InitCount();
	CMember::Outcount();

	CMember c1;
	c1.setData("성홍렬", "01077590276", "부산시 금정구");
	c1.getData();
	CMember::Outcount();

	CMember c2, *pc2;
	c2.setData("김영훈", "01012345678", "울산시 삼산동");
	c2.getData();
	pc2 = &c2;
	CMember::Outcount();
	delete pc2;
	CMember::Outcount();


	return 0;
}