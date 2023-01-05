#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//#include<stdio.h>
//namespace ytt
//{
//	int a = 5;
//	int Add(int a, int b)
//	{
//		return a + b;
//	}
//}

//namespace ytt
//{
//	int Add(int a, int b)
//	{
//		return a + b;
//	}
//	namespace wq
//	{
//		int Max(int a, int b)
//		{
//			return a > b ? a : b;
//		}
//	}
//}
//
//namespace ytt
//{
//	int a = 10;
//}
//int main()
//{
//	int a = 1;
//	//局部a
//	printf("a=%d\n", a);
//	//全局a
//	printf("a=%d\n", ytt::a);
//	//命名空间内的a
//	printf("a=%d\n", ::a);
//	return 0;
//}
//


//int main()
//{
//	int a = 0;
//	double b = 0;
//	char c = 0;
//	std::cin >> a >> b >> c;
//	std::cout << a <<std::endl;
//	std::cout << b << std::endl; 
//	std::cout << c << std::endl;
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	std::cin >> a;
//	std::cout << "a = " << a;
//}

//int main()
//{
//	std::cout << "hello world" << std:: endl;
//	std::cout << "hello world\n";
//}

//
//#include<iostream>
//namespace ytt
//{
//	int a = 0;
//	int b = 2;
//}
//using namespace ytt;
//using namespace std;
//int main()
//{
//	cout << a << endl;
//	cout << b << endl;
//}

//#include<iostream>
//namespace ytt
//{
//	int a = 0;
//	int b = 2;
//}
//using ytt::a;
//using ytt::b;
//using std::cout;
//using std::endl;
//int main()
//{
//	cout << a << endl;
//	cout << b << endl;
//}
//
//

#include<iostream>

using std::cout;
using std::endl;
void Func(int a = 10, int b = 20, int c = 30);
int main()
{
	Func();         //true
	return 0;
}
void Func(int a = 10, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}