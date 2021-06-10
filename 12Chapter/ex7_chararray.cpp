#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s("char array");
	string s2("char array2");

	cout << s.data() << endl;	// 맨 뒤에 널문자 삽입x
	cout << s.c_str() << endl;	// 맨 뒤에 널문자 삽입(c스타일)

	char str[128];
	strcpy(str, s.c_str());
	printf("str = %s\n", str);

	swap(s, s2);
	cout << s << ", " << s2 << endl;
}