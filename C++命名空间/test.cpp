#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
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

namespace ytt
{
	int a = 10;
}
int a = 5;
int main()
{
	int a = 1;
	//局部a
	printf("a=%d\n", a);
	//全局a
	printf("a=%d\n", ytt::a);
	//命名空间内的a
	printf("a=%d\n", ::a);
	return 0;
}


