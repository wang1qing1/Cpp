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

#define M 100
int main()
{
	const int a = 10;


	//权限平移
	const int& ra = a;
	const int& rm = M;

	return 0;
}