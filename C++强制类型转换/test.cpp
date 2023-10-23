#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//int main()
//{
//	int i = 1;
//	// 隐式类型转换
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//	int* p = &i;
//	// 显示的强制类型转换
//	int address = (int)p;
//	printf("%x, %d\n", p, address);
//
//	return 0;
//}

//
//int main()
//{
//	double a = 12.34;
//	int b = a;
//	int c = static_cast<int> (a);
//	int d = (int) & a;
//	//int e = static_cast<int> (&a); 类型转换无效
//	cout << "a:" << a << endl;
//	cout << "b:" << b << endl;
//	cout << "c:" << c << endl;
//	cout << "d:" << d << endl;
//
//	return 0;
//}

//int main()
//{
//	int a = 100;
//
//	int* p1 = (int*)a;
//	//用于不同类型间的强制转换
//	int* p2 = reinterpret_cast<int*>(a);
//
//	return 0;
//}

//
//int main()
//{
//	volatile const  int a = 100;
//	int* pa = (int*) & a;
//	*pa = 200;
//
//	printf("pa:%x -> %d\n", pa, *pa);
//	printf("&a:%x -> %d\n\n", &a, a);
//
//	volatile const int c = 1000;
//	int* pc = const_cast<int*> (&c);
//	*pc = 2000;
//
//	printf("pc:%x -> %d\n", pc, *pc);
//	printf("&c:%x -> %d\n", &c, c);
//	return 0;
//}


class A
{
public:
	virtual void f() {}
};

class B : public A
{};

void fun(A* pa,const string str)
{
	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回0
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);
	cout << str << "pb1:" << pb1 << endl;
	cout << str << "pb2:" << pb2 << endl;
}
int main()
{
	A a;
	B b;
	fun(&a,"父类,");
	fun(&b,"子类,");
	return 0;
}
