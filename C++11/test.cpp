#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<map>

using namespace std;


//struct Point
//{
//	int _x;
//	int _y;
//};
//int main()
//{
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//	Point p = { 1, 2 };
//	return 0;
//}
//struct Point
//{
//	int _x;
//	int _y;
//};
//int main()
//{
//	int x1 = 1;
//	//C++11
//	int x2{ 2 };
//	//C++11
//	int array1[]{ 1, 2, 3, 4, 5 };
//	int array2[5]{ 0 };
//	//C++11
//	Point p{ 1, 2 };
//	// C++11中列表初始化也可以适用于new表达式中
//	int* pa = new int[4] { 0 };
//	return 0;
//}

class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
//int main()
//{
//	Date d1(2022, 1, 1); // old style
//	// C++11支持的列表初始化，这里会调用构造函数初始化
//	Date d2{ 2022, 1, 2 };
//	Date d3 = { 2022, 1, 3 };
//	return 0;
//}

//int main()
//{
//	
//	list<int> li = { 10, 20, 30 };
//	
//	return 0;
//}

//int main()
//{
//	int i = 10;
//	auto p = &i;
//	auto pf = strcpy;
//	cout << typeid(p).name() << endl;
//	cout << typeid(pf).name() << endl;
//	map<string, string> dict = { {"sort", "排序"}, {"insert", "插入"} };
//	
//	auto it = dict.begin();//等价于map<string, string>::iterator it = dict.begin();
//	return 0;
//}

// decltype的一些使用使用场景
template<class T1, class T2>
void F(T1 t1, T2 t2)
{
	//将t1*t2的类型用来声明变量
	decltype(t1 * t2) ret;
	cout << typeid(ret).name() << endl;
}
int main()
{
	const int x = 1;
	double y = 2.2;
	decltype(x * y) ret; // ret的类型是double
	decltype(&x) p;		 // p的类型是int*
	cout << typeid(ret).name() << endl;
	cout << typeid(p).name() << endl;
	F(1, 'a');
	return 0;
}