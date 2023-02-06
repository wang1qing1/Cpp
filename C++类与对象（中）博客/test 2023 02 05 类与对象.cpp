#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	d1.Init(2022, 7, 5);
//	d1.Print();
//	Date d2;
//	d2.Init(2022, 7, 6);
//	d2.Print();
//	return 0;
//}

//class Date
//{
//public:
//	
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d2(2015, 1, 1);
//	return 0;
//}

//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{ 
//	Date d1;
//	d1.Print();
//
//	return 0;
//}
//
//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//	
//private:
//	// 基本类型(内置类型)
//	int _year = 2022;
//	int _month = 2;
//	int _day = 5;
//};
//int main()
//{
//	Date d;
//	d.Print();
//	return 0;
//}
//
//
//class Date{
//public:
//	Date(){
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//	}
//	Date(int year = 1900, int month = 1, int day = 1){
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 以下测试函数能通过编译吗？
//int main(){
//	//给出实际参数
//	Date d1(100,200,300);
//}

//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//	// 其他方法...
//
//	//析构函数
//	~Stack()
//	{
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//	
//private:
//	DataType* _array;
//	int _capacity;
//	int _size;
//};
//int main()
//{
//	Stack s;
//	s.Push(1);
//	s.Push(2);
//	return 0;
//}

//
//class Time
//{
//public:
//	~Time()
//	{
//		cout << "~Time()" << endl;
//	}
//private:
//	int _hour=0;
//	int _minute=0;
//	int _second=0;
//};
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		a = 10;
//		arr = (int*)malloc(sizeof(int) * a);
//		for (int i = 0; i < a; i++)
//		{
//			arr[i] = i;
//		}
//	}
//	void show()
//	{
//		for (int i = 0; i < a; i++)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << endl;
//	}
//
//	int* arr;
//	int a;
//};
//int main()
//{
//	A a;
//	A b(a);
//	//修改b对象的arr数组
//	for (int i = 0; i < b.a; i++)
//	{
//		b.arr[i]=0;
//	}
//	//观察两个对象中arr的元素
//	b.show();
//	a.show();
//	return 0;
//}
//
//
//
//
//





//class Time
//{
//public:
//	Time()
//	{
//		_hour = 1;
//		_minute = 1;
//		_second = 1;
//	}
//	//拷贝构造函数
//	Time(const Time& t)
//	{
//		_hour = t._hour;
//		_minute = t._minute;
//		_second = t._second;
//		cout << "Time::Time(const Time&)" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	void show()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	// 基本类型(内置类型)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d1;
//
//	// 用已经存在的d1拷贝构造d2，此处会调用Date类的拷贝构造函数
//	// 但Date类并没有显式定义拷贝构造函数，则编译器会给Date类生成一个默认的拷贝构造函数
//	Date d2(d1);
//	d1.show();
//	d2.show();
//	return 0;
//}
//
class Date
{
public:
	Date(int year, int minute, int day)
	{
		cout << "Date(int,int,int):" << this << endl;
	}
	Date(const Date& d)
	{
		cout << "Date(const Date& d):" << this << endl;
	}
	~Date()
	{
		cout << "~Date():" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
Date Test(const Date& d)
{
	Date temp(d);
	return temp;
}
int main()
{
	Date d1(2022, 1, 13);
	Test(d1);
	return 0;
}