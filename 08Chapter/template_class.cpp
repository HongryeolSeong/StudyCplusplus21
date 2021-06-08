#include <iostream>
using namespace std;
// 클래스 템플릿(일반화)

template <typename T>
class CTest
{
private:
	int num;
public:
//	CTest(T anum) : num(anum) { };
	CTest(T);	// 밖에서 선언시
	void printData() {
		cout << "num : " << num << endl;
	}
};

template <typename T>	// 템플릿 선언 한 번 더 한다.
CTest<T>::CTest(T anum) {
	num = anum;
}

int main()
{
//	CTest obj(10); CTest는 템플릿이므로 이름만으로는 객체 생성 불가
	CTest<int> obj(10);
	obj.printData();
	
	return 0;
}