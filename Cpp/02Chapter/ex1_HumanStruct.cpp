#include <iostream>

struct Human {
	char name[20];
	float height;
	float weight;
	int age;
	char blood;
};

int main()
{
	Human my = { "¼ºÈ«·Ä", 172, 65, 27, 'A' };
	printf("%s %.1lf %.1lf %d %c", my.name, my.height, my.weight, my.age, my.blood);
	return 0;
}