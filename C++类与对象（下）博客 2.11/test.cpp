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
//		:_aobj(a) //���ù��캯��
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	A _aobj; //û��Ĭ�Ϲ��캯��
//	int& _ref; //����
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
//	// 1. ���ι��캯����û��ʹ��explicit���Σ���������ת������
//	explicit Date(int year)
//	{
//		_year = year;
//		_month = 0;
//		_day = 0;
//	}
//	// 2. ��Ȼ�ж�����������Ǵ�������ʱ�������������Բ����ݣ�û��ʹ��explicit���Σ���
//	//������ת������
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
//	//����ת��
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
//	//��Ԫ����
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
//	cout << "���룺";
//	cin >> d;
//	cout << d << endl;
//	Fun();
//	return 0;
//}
//
//class Time
//{
//	friend class Date; //����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
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
//		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
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
//	class B // B��������A����Ԫ
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
	// ��ֵ����,�ȹ��죬�ٿ������졣
	A aa1;
	f1(aa1);
	cout << endl;
	// ��ֵ���أ��ȹ��죬�ٿ������졣
	f2();
	cout << endl;
	// ��ʽ���ͣ�δ�Ż����ȹ��죬�ٿ������� -> �Ż�Ϊֱ�ӹ��졣
	f1(1);
	// һ�����ʽ�У��ȹ��죬�ٿ������� -> �Ż�Ϊһ�����졣
	f1(A(2));
	cout << endl;
	// һ�����ʽ�У��ȹ��죬�ٿ������죬�ٿ������� ->�Ż�Ϊ ����+�������졣
	A aa2 = f2();
	cout << endl;
	// һ�����ʽ�У��ȹ��죬�ٿ������죬�ٸ�ֵ���� ->�޷��Ż���
	aa1 = f2();
	cout << endl;

	return 0;
}

