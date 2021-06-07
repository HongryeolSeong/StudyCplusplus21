#include <iostream>
using namespace std;
// 템플릿 활용한 다양한 타입의 배열 생성

template <typename T, int sz = 3>	// sz는 디폴트 템플릿 인수
class CTest
{
private:
	T ary[sz];
public:
	T& operator [](int idx) {
		if (idx < 0 || idx >= sz) {
			cout << "error" << endl;
			exit(1);
		}
		return ary[idx];
	}

	void getData() {
		for (int i = 0; i < sz; i++)
		{
			cout << ary[i] << " ";
		}
	}
};

int main()
{
	CTest<int, 3> arr;
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;

	arr.getData();

	return 0;
}