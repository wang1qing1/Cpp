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
//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	bool operator ==(const Date& date)
//	{
//		return _year == date._year && _month == date._month && _day == date._day;
//	}
//	void show()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//	
//	int _year;
//	int _month;
//	int _day;
//};
////函数判断日期相等
//bool DateEqual(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year &&
//		d1._month == d2._month &&
//		d1._day == d2._day;
//}
////运算符重载的定义 使用关键字 operator 【运算符】
//bool operator==(const Date& d1 ,const Date& d2)
//{
//	return d1._year == d2._year &&
//		   d1._month == d2._month && 
//		   d1._day == d2._day;
//}
//int main()
//{
//	Date d2(2022, 1, 13);
//	Date d1(2022, 1, 13);
//	//运算符重载的使用
//	if (d1 == d2)
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//	
//	return 0;
//}

//class Date{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	int _year;
//	int _month;
//	int _day;
//};
////赋值运算符重载成全局函数,注意重载成全局函数时没有this指针了，需要给两个参数
//Date& operator=(Date& left, const Date& right)
//{
//	if (&left != &right)
//	{
//		left._year = right._year;
//		left._month = right._month;
//		left._day = right._day;
//	}
//	return left;
//}
//

//int main()
//{
//	Date date1;
//	Date date2(2023, 2, 7);
//	//date1.show();
//	////因为有返回值就可以实现链式访问
//	//(date1 = date2).show();
//	
//	return 0;
//}
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
//	Time& operator=(const Time& t)
//	{
//		if (this != &t)
//		{
//			cout << "Time:operator=" << endl;
//			_hour = t._hour;
//			_minute = t._minute;
//			_second = t._second;
//		}
//		return *this;
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
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void show()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	// 基本类型(内置类型)
//	int _year ;
//	int _month;
//	int _day;
//	// 自定义类型
//	Time _t;
//};
//int main()
//{
//	Date d1;
//	d1.show();
//	Date d2(2023,2,7);
//	d1 = d2;
//	d1.show();
//	return 0;
//}
//
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
//	A b;
//	a.show();
//	b.show();
//	b = a;
//	//修改b对象的arr数组
//	for (int i = 0; i < b.a; i++)
//	{
//		b.arr[i] = 0;
//	}
//	//观察两个对象中arr的元素
//	b.show();
//	a.show();
//	return 0;
//}
//

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	// 前置++：返回+1之后的结果
//	// 注意：this指向的对象函数结束后不会销毁，故以引用方式返回提高效率
//	Date& operator++()
//	{
//		_day += 1;
//		return *this;
//	}
//	// 后置++：
//	// 前置++和后置++都是一元运算符，为了让前置++与后置++形成能正确重载
//	// C++规定：后置++重载时多增加一个int类型的参数，但调用函数时该参数不用传递，编译器自动传递
//	// 注意：后置++是先使用后+1，因此需要返回+1之前的旧值，故需在实现时需要先将this保存一份，然后给this + 1
//	// 而temp是临时对象，因此只能以值的方式返回，不能返回引用
//	Date operator++(int)
//	{
//		Date temp(*this);
//		_day += 1;
//		return temp;
//	}
//	void show()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2022, 10, 1);
//	d1.show();
//	Date d2 = d1++;
//	d2.show();
//	d1.show();
//
//	d2 = ++d1;
//	d1.show();
//	d2.show();
//
//	return 0;
//}
//

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		ConstPrint();
//		cout << "Print()" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//	void ConstPrint() const
//	{
//		cout << "Print()const" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl << endl;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//int main()
//{
//	Date d1(2022, 1, 13);
//	d1.Print();
//	const Date d2(2022, 1, 13);
//	d2.ConstPrint();
//	return 0;
//}
//
//

//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date* operator&()
//	{
//		return (Date*)0x00000001;
//	}
//	const Date* operator&()const
//	{
//		return (Date*)0x0000250;
//	}
//private:
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//};
//
//int main()
//{
//	const Date date(2022,10,1);
//	Date date1(date);
//	cout << &date << endl;
//	cout << &date1 << endl;
//
//	return 0;
//}
