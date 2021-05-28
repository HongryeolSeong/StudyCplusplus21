// cout사용시 선언
#include <iostream>
using namespace std;

int main()
{
	// cout : 출력 객체, << : 연산자, endl : 개행
	// cout에 <<로 데이터를 보낸다.
	cout << "First C++ Program" << endl;
	// std::cout << "First C++ Program" << std::endl; // std 선언 없을시

	int i = 56;
	char ch = 'S';
	double d = 2.414;

	cout << i << ch << d << endl;

	return 0;
}