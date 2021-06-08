#include <iostream>
using namespace std;
// 함수 템플릿(특수화)

template <typename T>
T Add(T a, T b)
{
	return a + b;
}

template <> 
const char* Add(const char* lstr, const char* rstr)
{
	int llen = strlen(lstr);
	int rlen = strlen(rstr);
	int len = llen + rlen + 1;
	char* str = new char[len];

	strcpy_s(str, llen + 1, lstr);
	strcat_s(str, len, rstr);

	return str;
}

int main()
{
	int res = Add<int>(3, 4);	// 5번 행 실행
	cout << res << endl;

	const char* sres = Add<const char*>("Hello", " Iot");	// 12번 행 실행
	cout << sres << endl;

	return 0;
}