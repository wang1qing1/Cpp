#define _CRT_SECURE_NO_WARNINGS 1
#include"Vector.h"
using namespace ikun;
int main()
{
	Vector<int> v;
	v.push_bank(100);
	v.push_bank(200);
	v.push_bank(300);
	v.push_bank(400);
	v.push_bank(500);
	v.push_bank(600);
	v.push_bank(700);
	v.push_bank(900);
	v.insert(v.begin()+3, 1234);
	v.erase(v.begin());
	//for (auto it = v.begin(); it != v.end(); it++)
	//{
	//	printf("%d ",*it);
	//}
	//std::cout << std::endl;
	//for (int i = 0; i < v.size(); i++)
	//{
	//	printf("%d ", v[i]);
	//}
	/*int a = 10; int b = 20;
	printf("\n%d %d\n", a, b);
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("%d %d", a, b);*/

	/*int a = 10;
	int& pa = a;
	cout << a << endl;
	pa = 100;
	cout << a << endl;*/

	return 0;
}