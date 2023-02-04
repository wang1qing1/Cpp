#define _CRT_SECURE_NO_WARNINGS 
#include"class.h"



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

//class className
//{
//	// 类体：由成员函数和成员变量组成
//
//}; //一定要注意后面的分号


// 我们看看这个函数，是不是很僵硬？
//class Date
//{
//	void Init(int year)
//	{
//		// 这里的year到底是成员变量，还是函数形参？
//		year = year;
//	}
//
//	int year;
//};
//
//class Date
//{
//	void Init(int year)
//	{
//		_year = year;
//	}
//
//	int _year;
//};
//// 或者这样
//class Date
//{
//	void Init(int year)
//	{
//		mYear = year;
//	}
//
//	int mYear;
//};
//class Person
//{
//public:
//	void PrintPersonInfo();
//
//	const char *m_name;
//	char m_gender[3];
//	int m_age;
//};
////这里需要指定PrintPersonInfo是属于Person这个类域
//void Person::PrintPersonInfo()
//{
//	cout << m_name << " " << m_gender << " " <<m_age<< endl;
//}
//
//class A
//{
//public:
//	void show()
//	{
//		cout << a << b << endl;
//	}
//private:
//	int a;
//	int b;
//};
//class B
//{
//
//};
//int main()
//{
//	A a;
//	B b;
//	cout << sizeof(b) << endl;
//	return 0;
//}
//class Date{
//public:
//	void Init(int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void Print()
//	{
//		cout << this->_year << "/" << this->_month << "/" << this->_day << endl;
//	}
//	void Display()
//	{
//		cout << _year << endl;
//	}
//	void Display(Date* this)
//	{
//		cout << this->_year << endl;
//	}
//private:
//	int _year;   //年
//	int _month;  //月 
//	int _day;    //日   
//};
//int main()
//{
//	Date d1, d2;
//	d1.Init(2022, 1, 11);
//	d2.Init(2022, 1, 12);
//	d1.Print();
//	d2.Print();
//	return 0;
//}

//class A
//{
//public:
//	void Print()
//	{
//		cout << _a << endl;
//	}
//
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	return 0;
//}
//



//
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->PrintA();
//	return 0;
//}

//typedef int DataType;
//typedef struct Stack
//{
//	DataType* array;//数据域
//	int capacity;//容量
//	int size;//栈顶、数据个数
//}Stack;
////初始化
//void StackInit(Stack* ps)
//{
//	assert(ps);
//	ps->array = (DataType*)malloc(sizeof(DataType) * 3);
//	if (NULL == ps->array)
//	{
//		assert(0);
//		return;
//	}
//	ps->capacity = 3;
//	ps->size = 0;
//}
////销毁
//void StackDestroy(Stack* ps)
//{
//	assert(ps);
//	if (ps->array)
//	{
//		free(ps->array);
//		ps->array = NULL;
//		ps->capacity = 0;
//		ps->size = 0;
//	}
//}
////检查扩容
//void CheckCapacity(Stack* ps)
//{
//	if (ps->size == ps->capacity)
//	{
//		int newcapacity = ps->capacity * 2;
//		DataType* temp = (DataType*)realloc(ps->array,
//			newcapacity * sizeof(DataType));
//		if (temp == NULL)
//		{
//			perror("realloc申请空间失败!!!");
//			return;
//		}
//		ps->array = temp;
//		ps->capacity = newcapacity;
//	}
//}
////入栈
//void StackPush(Stack* ps, DataType data)
//{
//	assert(ps);
//	CheckCapacity(ps);
//	ps->array[ps->size] = data;
//	ps->size++;
//}
////栈判空
//int StackEmpty(Stack* ps)
//{
//	assert(ps);
//	return 0 == ps->size;
//}
////出栈
//void StackPop(Stack* ps)
//{
//	if (StackEmpty(ps))
//		return;
//	ps->size--;
//}
////栈顶数据
//DataType StackTop(Stack* ps)
//{
//	assert(!StackEmpty(ps));
//	return ps->array[ps->size - 1];
//}
////栈数据个数
//int StackSize(Stack* ps)
//{
//	assert(ps);
//	return ps->size;
//}
//int main()
//{
//	Stack s;
//	StackInit(&s);
//	StackPush(&s, 1);
//	StackPush(&s, 2);
//	StackPush(&s, 3);
//	StackPush(&s, 4);
//	printf("%d\n", StackTop(&s));
//	printf("%d\n", StackSize(&s));
//	StackPop(&s);
//	StackPop(&s);
//	printf("%d\n", StackTop(&s));
//	printf("%d\n", StackSize(&s));
//	StackDestroy(&s);
//	return 0;
//}

typedef int DataType;
class Stack
{
public:
	//初始化
	void Init()
	{
		_array = (DataType*)malloc(sizeof(DataType) * 3);
		if (NULL == _array)
		{
			perror("malloc申请空间失败!!!");
			return;
		}
		_capacity = 3;
		_size = 0;
	}
	//入栈
	void Push(DataType data)
	{
		CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	//出栈
	void Pop()
	{
		if (Empty())
			return;
		_size--;
	}
	//得到栈顶数据
	DataType Top() { return _array[_size - 1]; }
	//栈判空
	int Empty() { return 0 == _size; }
	//得到站的数据个数
	int Size() { return _size; }
	//栈销毁
	void Destroy()
	{
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	//检查扩容
	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			int newcapacity = _capacity * 2;
			DataType* temp = (DataType*)realloc(_array, newcapacity *
				sizeof(DataType));
			if (temp == NULL)
			{
				perror("realloc申请空间失败!!!");
				return;
			}
			_array = temp;
			_capacity = newcapacity;
		}
	}
private:
	DataType* _array;
	int _capacity;
	int _size;
};
int main()
{
	Stack s;
	s.Init();
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	printf("%d\n", s.Top());
	printf("%d\n", s.Size());
	s.Pop();
	s.Pop();
	printf("%d\n", s.Top());
	printf("%d\n", s.Size());
	s.Destroy();
	return 0;
}