#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;



class Date
{
	friend ostream& operator<<(ostream& out, const Date& d)
	{
		out << d._year << "/" << d._month << "/" << d._day << endl;
		return out;
	}
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
private:
	int _year;
	int _month;
	int _day;
};

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//class B
//{
//public:
//	B(int a, int ref)
//		:_aobj(a) //调用构造函数
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	A _aobj; //没有默认构造函数
//	int& _ref; //引用
//	const int _n; //const
//};
//
//int main()
//{
//	
//	B b(10,10);
//	return 0;
//}
//
//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main() {
//	A aa(1);
//	aa.Print();
//}
class Date
{
	friend ostream& operator<<(ostream& out, const Date& d)
	{
		out << d._year << "/" << d._month << "/" << d._day << endl;
		return out;
	}
public:
	// 1. 单参构造函数，没有使用explicit修饰，具有类型转换作用
	explicit Date(int year)
	{
		_year = year;
		_month = 0;
		_day = 0;
	}
	// 2. 虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具
	//有类型转换作用
	//Date(int year, int month = 1, int day = 1)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	//类型转换
	Date date = 100;
	cout << date;
	return 0;
}