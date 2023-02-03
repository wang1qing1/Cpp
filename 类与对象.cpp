#define _CRT_SECURE_NO_WARNINGS 
#include<stdlib.h>
#include<iostream>
#include<assert.h>
using namespace std;
int add(int& a, int& b);



//struct D
//{
//	D(int i = 0, int j = 10)
//	{
//		year = i;
//		day = j;
//	}
//	int year;
//	int day;
//};
//class Date
//{
//public:
//	//Date(int year = 0,int day=1,int mon=1 )
//	//{
//	//	_year = year;
//	//	_day = day;
//	//	_mon = mon;
//	//}
//	void show()
//	{
//		cout << _day << endl;
//		cout << d.day << endl;
//	}
//	/*Date( const Date& d )
//	{
//		_year = d._year; 
//		_mon = d._mon;
//		_day = d._day;
//	}*/
//	int _year ;
//	int _mon ;
//	int _day ;
//	D d;
//};
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
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year;
//	int _month;
//	int _day;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d;
//	return 0;
//}
//int main()
//{
//	Date date;
//	date.show();
//	//Date date1(date);
//	//date1.show();
//	return 0;
//}


//struct Stact
//{
//	typedef int STDateType;
//	
//	void Init(int n = 4)//缺省参数
//	{
//		capacity = n;
//		top = 0;
//		date = (STDateType*)malloc(sizeof(STDateType)*capacity);
//	}
//
//	void PushBank(STDateType x)
//	{
//		
//		if (capacity == top)
//		{
//			STDateType* tmp = (STDateType*)realloc(date, sizeof(STDateType) *capacity * 2);
//			if (tmp == NULL)
//			{
//				perror("realloc");
//				exit(-1);
//			}
//			date = tmp;
//			capacity *= 2;
//		}
//		date[top++] = x;
//	}
//
//	bool Empty()
//	{
//		//....
//	}
//
//	STDateType Top()
//	{
//		//....
//	}
//
//	//...
//	STDateType* date;
//	int capacity;
//	int top;
//};
//
//int main()
//{
//	//直接使用结构体名称定义变量
//	Stact S;
//	//访问结构体成员
//	S.Init();
//	S.PushBank(100);
//	S.PushBank(200);
//	S.PushBank(300);
//	//检验
//	for (int i = 0; i < S.top; i++)
//	{
//		cout << S.date[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}

class className
{
	// 类体：由成员函数和成员变量组成

}; //一定要注意后面的分号

int main()
{
	
	return 0;
}