#include <stdio.h>

class MyTest 
{
private:
	int x;
	int y;
	
public:
	MyTest() { }

	MyTest(int ax, int ay) { x = ax; y = ay; }

	void OutValue() {
		printf("%d, %d\n", x, y);
	}

	const MyTest Sum(const MyTest& other) const {
		MyTest t;

		t.x = this->x + other.x;
		t.y = this->y + other.y;
		
		return t;
	}
};

int main()
{
	MyTest obj1(10, 20);
	MyTest obj2(20, 10);
	MyTest obj;
	obj = obj1.Sum(obj2);
	obj.OutValue();


	return 0;
}