#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
//int main()
//{
//	int a = 10;
//	int& ra = a;
//	std::cout << "a=" << a << endl;
//	std::cout << "ra=" << ra << endl;
//	ra = 20;
//	std::cout << "a=" << a << endl;
//	std::cout << "ra=" << ra << endl;
//
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;
//	int& rb = a;
//	int& rc = a;
//	
//	printf("ra=%d,rb=%d,rc=%d\n",ra,rb,rc);
//	return 0;
//}
//
//int main()
//{
//	int a = 10; 
//	int b = 30;
//	int& ra = a;
//	ra = b;//仅仅只是把b的值赋值给了ra
//
//	std::cout << &a << endl;
//	std::cout << &ra << endl;
//	std::cout << &b << endl;
//	std::cout << "a=" << a << " b=" << b << endl;
//
//	return 0;
//}


//#define M 100
//int main()
//{
//	const int a = 10;
//	//权限放大
//	int& ra = a;// 该语句编译时会出错，a为常量
//	int& rm = M;// 该语句编译时会出错，M为常量
//	//权限平移
//	const int& ra = a;
//	const int& rm = M;
//
//	return 0;
//}


//#define M 100
//int main()
//{
//	const int a = 10;
//
//	//权限平移
//	const int& ra = a;
//	const int& rm = M;
//
//	return 0;
//}

//#define M 100
//int main()
//{
//	const int a = 10;
//
//
//	//权限平移
//	const int& ra = a;
//	const int& rm = M;
//
//	return 0;
//}

//int main()
//{
//	const int a = 10;
//	//权限放大
//	int* pa = &a;
//
//	//权限平移
//	const int* ra = &a;
//
//	return 0;
//}

//int main()
//{
//	double b = 1.23;
//
//	int& rb = b;//
//	const int& rrb = b;
//
//	return 0;
//}




//
//void Swap(int* pleft, int* pright)
//{
//	int tmp = *pleft;
//	*pleft = *pright;
//	*pright = tmp;
//}
//
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//int main()
//{
//	int a = 10; int b = 20;
//	std::cout << "交换前a="<< a << ",b=" << b << endl;
//	
//	Swap(a, b);
//	
//	std::cout << "交换后a=" << a << ",b=" << b << endl;
//	return 0;
//}

int& add(int a, int b)
{
	static int sum = a + b;
	return sum;
}
//#include <time.h>
//struct A { int a[10000]; };
//void TestFunc1(A a) {}
//void TestFunc2(A& a) {}
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}

//#include <time.h>
//struct A { int a[10000]; };
//A a;
//// 值返回
//A TestFunc1() { return a; }
//// 引用返回
//A& TestFunc2() { return a; }
//void TestReturnByRefOrValue()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//int main()
//{
//	TestReturnByRefOrValue();
//	return 0;
//}
int main()
{
	int a = 10;
	int& ra = a;
	ra = 20;
	int* pa = &a;
	*pa = 20;
	int*(*(*fun)(int* (*)[10], char* (*)[5]))[10];
	cout << typeid(fun).name() << endl;
	return 0;
}

// fun(int(*)[10], int(*)[5]);
