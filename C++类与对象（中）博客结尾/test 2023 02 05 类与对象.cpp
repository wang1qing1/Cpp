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
//	// ��������(��������)
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
//// ���²��Ժ�����ͨ��������
//int main(){
//	//����ʵ�ʲ���
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
//			perror("malloc����ռ�ʧ��!!!");
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
//	// ��������...
//
//	//��������
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
//	// ��������(��������)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// �Զ�������
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
//	//�޸�b�����arr����
//	for (int i = 0; i < b.a; i++)
//	{
//		b.arr[i]=0;
//	}
//	//�۲�����������arr��Ԫ��
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
//	//�������캯��
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
//	// ��������(��������)
//	int _year = 1970;
//	int _month = 1;
//	int _day = 1;
//	// �Զ�������
//	Time _t;
//};
//int main()
//{
//	Date d1;
//
//	// ���Ѿ����ڵ�d1��������d2���˴������Date��Ŀ������캯��
//	// ��Date�ಢû����ʽ���忽�����캯��������������Date������һ��Ĭ�ϵĿ������캯��
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
////�����ж��������
//bool DateEqual(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year &&
//		d1._month == d2._month &&
//		d1._day == d2._day;
//}
////��������صĶ��� ʹ�ùؼ��� operator ���������
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
//	//��������ص�ʹ��
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
////��ֵ��������س�ȫ�ֺ���,ע�����س�ȫ�ֺ���ʱû��thisָ���ˣ���Ҫ����������
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
//	////��Ϊ�з���ֵ�Ϳ���ʵ����ʽ����
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
//	// ��������(��������)
//	int _year ;
//	int _month;
//	int _day;
//	// �Զ�������
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
//	//�޸�b�����arr����
//	for (int i = 0; i < b.a; i++)
//	{
//		b.arr[i] = 0;
//	}
//	//�۲�����������arr��Ԫ��
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
//	// ǰ��++������+1֮��Ľ��
//	// ע�⣺thisָ��Ķ����������󲻻����٣��������÷�ʽ�������Ч��
//	Date& operator++()
//	{
//		_day += 1;
//		return *this;
//	}
//	// ����++��
//	// ǰ��++�ͺ���++����һԪ�������Ϊ����ǰ��++�����++�γ�����ȷ����
//	// C++�涨������++����ʱ������һ��int���͵Ĳ����������ú���ʱ�ò������ô��ݣ��������Զ�����
//	// ע�⣺����++����ʹ�ú�+1�������Ҫ����+1֮ǰ�ľ�ֵ��������ʵ��ʱ��Ҫ�Ƚ�this����һ�ݣ�Ȼ���this + 1
//	// ��temp����ʱ�������ֻ����ֵ�ķ�ʽ���أ����ܷ�������
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
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
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
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
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
