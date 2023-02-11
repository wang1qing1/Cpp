#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;



//class Date
//{
//	friend ostream& operator<<(ostream& out, const Date& d)
//	{
//		out << d._year << "/" << d._month << "/" << d._day << endl;
//		return out;
//	}
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

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
//class Date
//{
//	friend ostream& operator<<(ostream& out, const Date& d)
//	{
//		out << d._year << "/" << d._month << "/" << d._day << endl;
//		return out;
//	}
//public:
//	// 1. 单参构造函数，没有使用explicit修饰，具有类型转换作用
//	explicit Date(int year)
//	{
//		_year = year;
//		_month = 0;
//		_day = 0;
//	}
//	// 2. 虽然有多个参数，但是创建对象时后两个参数可以不传递，没有使用explicit修饰，具
//	//有类型转换作用
//	//Date(int year, int month = 1, int day = 1)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	//类型转换
//	Date date = 100;
//	cout << date;
//	return 0;
//}
//class A
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//	A(const A& t)
//	{
//		++_scount;
//	}
//	static int GetACount() { return _scount; }
//private:
//	static int _scount;
//};
//int A::_scount = 0;
//A Fun(A a4)
//{
//	A tmp(a4);
//	return tmp;
//}
//int main()
//{
//	A* ptr = nullptr;
//	cout << ptr->GetACount() << endl;
//	return 0;
//}
//class A
//{
//public:
//	void show()
//	{
//		cout << "void show()" << endl;
//		GetACount();
//	}
//	static int GetACount() 
//	{
//		cout << "static int GetACount()" << endl;
//		return _scount; 
//	}
//	static int _scount;
//	int n = 100;
//};
//int A::_scount = 0;
//int main()
//{
//	A a;
//	a.show();
//	return 0;
//}

//class Date
//{
//	//友元函数
//	const friend int get(Date& d);
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "/" << d._month << "/" << d._day;
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//
//void fun1()
//{
//	cout << "fun1()" << endl;
//}
//const int  Fun()
//{
//	int x = 5;
//	fun1();
//	cout << "const int Fun()" << endl;
//	return x;
//}
//int main()
//{
//	
//	Date d;
//	cout << "输入：";
//	cin >> d;
//	cout << d << endl;
//	Fun();
//	return 0;
//}
//
//class Time
//{
//	friend class Date; //声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//	void Show()
//	{
//		cout << _year << "/" << _month << "/" << _day 
//			<< " " << _t._hour << ":" << _t._minute << ":" << _t._second << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//int main()
//{
//	Date d(2023, 2, 11);
//	d.SetTimeOfDate(10, 0, 0);
//	d.Show();
//	return 0;
//}

//class A
//{
//private:
//	static int k;
//	int h;
//public:
//	void show()
//	{
//		cout << h << endl;
//	}
//	class B // B天生就是A的友元
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a.h << endl;//OK
//		}
//	};
//};
//
//int A::k = 1;
//
//class D
//{
//public:
//	~D()
//	{
//		cout << "~D()" << endl;
//	}
//	int b = 10;
//	int a;
//};
//int main(){
//	//char str[] = "dhkjshd";
//	//const char* str1 = "hsdkudh";
//	//A::B b;
//	//A a;
//	//a.show();
//	//b.foo(A());
//	//A().show();
//	D* d = new D[10];
//	//free(d);
//	d=(D*)((int)d - 4);
//	free(d);
//	return 0;
//}
//
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//...
//		return n;
//	}
//};
//int main()
//{
//	cout << Solution().Sum_Solution(10) << endl;
//	return 0;
//}
//	
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}
	/*~A()
	{
		cout << "~A()" << endl;
	}*/
private:
	int _a;
};
void f1(A aa)
{}
A f2()
{
	A aa;
	return aa;
}
int main()
{
	// 传值传参,先构造，再拷贝构造。
	A aa1;
	f1(aa1);
	cout << endl;
	// 传值返回，先构造，再拷贝构造。
	f2();
	cout << endl;
	// 隐式类型，未优化：先构造，再拷贝构造 -> 优化为直接构造。
	f1(1);
	// 一个表达式中，先构造，再拷贝构造 -> 优化为一个构造。
	f1(A(2));
	cout << endl;
	// 一个表达式中，先构造，再拷贝构造，再拷贝构造 ->优化为 构造+拷贝构造。
	A aa2 = f2();
	cout << endl;
	// 一个表达式中，先构造，再拷贝构造，再赋值重载 ->无法优化。
	aa1 = f2();
	cout << endl;

	return 0;
}

