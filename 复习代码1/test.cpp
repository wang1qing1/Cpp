#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include"Test.h"

using namespace std;
void Print(const vector<int>& vv)
{
	for (auto e : vv)cout << e << " ";
	cout << endl;
}
//struct Com
//{
//	bool operator()(int a, int b)
//	{
//		return a > b;
//	}
//	int a = 10;
//};
//int main()
//{
//	//vector<int> v1(3,200);
//	//vector<int>  v2(5, 100);
//	//swap(v1, v2);
//	//Print(v1);
//	//Print(v2);
//	vector<int> vv = { 2,1,4,3 };
//	priority_queue<int, vector<int>, Com> q(vv.begin(), vv.end());
//	while (!q.empty())
//	{
//		cout << q.top() << endl;
//		q.pop();
//	}
//	Com c;
//	sort(vv.begin(), vv.end());
//	cout << sizeof c << endl;
//	/*do
//	{
//		Print(vv);
//	} while (prev_permutation(vv.begin(), vv.end()));*/
//
//	return 0;
//}


inline int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a + b;
}



//class A
//{
//public:
//	A(int _a,int _b)
//		:a(_a),b(_b)
//	{}
//	inline virtual int add()
//	{
//		return a + b;
//	}
//public:
//	int a;
//	int b;
//};
//class AA :public  A
//{
//public:
//	AA(int b,int c)
//		:_b(b),_c(c),A(2,3)
//	{}
//	inline virtual int add()
//	{
//		return _b + _c;
//	}
//	int _b;
//	int _c;
//};
//
//int sub(int a, int b = 10)
//{
//
//}
//
//int main()
//{
//	A a(2,2);
//	AA aa(5, 3);
//	A& paa = aa;
//	A& pa = a;
//	cout << paa.add() << endl;
//	cout << pa.add() << endl;
//
//	return 0;
//}


//class Person
//{
//public:
//	Person()
//	{}
//
//	int getstatic()
//	{
//		return tmp;
//	}
//
//	static void Print()
//	{
//		cout << "static Print()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//class student :public Person
//{
//public:
//	student()
//		:Person()
//	{}
//	~student()
//	{}
//};

template<class T>
void Swap(T &a,T& b)
{
	T tmp = a;
	a = b; 
	b = tmp;

}

//静态数组
template<class T, size_t N = 10>
class array
{
public:
	T& operator[](size_t index) { return _array[index]; }
	const T& operator[](size_t index)const { return _array[index]; }
	size_t size()const { return _size; }
	bool empty()const { return 0 == _size; }
private:
	T _array[N];
	size_t _size;
};



//class A
//{
//public:
//	A(int i)
//	{
//		cout << "A(int i)" << endl;
//	}
//	A(const A& a)
//	{
//		_aa = a._aa;
//	}
//
//	//赋值运算符重载
//	A& operator=(const A& a)
//	{
//		if (this != &a)
//		{
//			_aa = a._aa;
//		}
//		return *this;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//	int _aa;
//};
//class B : public A
//{
//public:
//	//A中没有默认构造函数，B就必须显示调用A的构造函数
//	B()
//		:A(1)
//	{
//		cout << "B()" << endl;
//	}
//	B(const B& b)
//		:A(b)//基类拷贝构造,拷贝基类的那部分
//	{
//		_bb = b._bb;//派生类的单独拷贝
//	}
//
//	B& operator=(const B& b)
//	{
//		if (&b != this)
//		{
//			A::operator=(b);//调用基类的赋值重载运算符，完成继承部分的赋值。
//			_bb = b._bb;//派生类自己的单独赋值。
//		}
//		return *this;
//	}
//
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//	int _bb;
//};

class Person {
public:
	virtual Person* BuyTicket() { cout << "买票-全价" << endl; return nullptr; }
	virtual ~Person() { cout << "~Person()" << endl; }
};
class Student : public Person {
public:
	//virtual void BuyTicket() { cout << "买票-半价" << endl; }
	virtual Student* BuyTicket() { cout << "买票-半价" << endl; return nullptr; }
	~Student() { cout << "~Student()" << endl; }
};
//
//class Base
//{
//public:
//	virtual void Func1() { cout << "Base::Func1()" << endl; }
//	virtual void Func2() { cout << "Base::Func2()" << endl; }
//	virtual void Func3() { cout << "Base::Func3()" << endl; }
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1() { cout << "Derive::Func1()" << endl; }
//	virtual void Func2() { cout << "Derive::Func2()" << endl; }
//private:
//	int _d = 2;
//};

// 这里常考一道笔试题：sizeof(Base)是多少？
//class Base
//{
//public:
//	 virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class drive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _d = 1;
//};
//
//inline void aa()
//{
//	int a = 10;
//	a++;
//}
//
//int main()
//{
//
//	Base b1;
//	Base b2;
//	drive d;
//	return 0;
//}


class A {
public:
	A(const char* s) { cout << s << endl; }
	~A() {}
};
class B :virtual public A
{
public:
	B(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
};
class C :virtual public A
{
public:
	C(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
};

class D :public B, public C
{
public:
	D(const char* s1, const char* s2, const char* s3, const char* s4) :B(s1, s2), C(s1, s3), A(s1)
	{
		cout << s4 << endl;
	}
};
#include<functional>

//class Add
//{
//public:
//	Add(int a)
//		:_a(a)
//	{}
//	int add(int b)
//	{
//		return _a + b;
//	}
//	static int s_add(int a, int b)
//	{
//		return a + b;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	//包装非静态成员函数,用对象构建
//	function<int(Add, int)> fun1 = &Add::add;
//	cout << fun1(Add(10), 30) << endl;
//
//	//包装非静态成员函数，用对象指针构建
//	Add add(10);
//	function<int(Add*, int)> fun3 = &Add::add;
//	cout << fun3(&add, 30) << endl;
//
//	//包装静态成员函数
//	function<int(int, int)> fun2 = Add::s_add;
//	cout << fun2(10, 30) << endl;
//
//	return 0;
//}
//
//#include<functional>
//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
//}
//double f(double i)
//{
//	return i / 2;
//}
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};

template<class T>
class myatuo_ptr
{
public:
	myatuo_ptr(T* ptr)
		:_ptr(ptr)
	{
	}

	//像指针一样访问
	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }


	//管理权转移，一次只能有一个对象管理资源
	myatuo_ptr& operator=(myatuo_ptr& ptr)
	{
		//不是自己给自己赋值
		if (this != &ptr)
		{
			//1.先释放当前管理的资源
			if (_ptr)
			{
				delete _ptr;
			}
			//2.转移管理权
			_ptr = ptr._ptr;
			ptr._ptr = nullptr;
		}
		return *this;
	}

	~myatuo_ptr()
	{
		if (_ptr)
			delete _ptr;
	}

private:
	T* _ptr;
};

template<class T>
class myunique_ptr
{
public:
	myunique_ptr(T* ptr)
		:_ptr(ptr)
	{}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	myunique_ptr(myunique_ptr& ptr) = delete;
	void operator=(myunique_ptr& ptr) = delete;

	~myunique_ptr()
	{
		if (_ptr)
		{
			cout << "~myunique_ptr()" << endl;
			delete _ptr;
		}
	}
private:
	T* _ptr;
};

template<class T>
class myshared_ptr
{
public:
	myshared_ptr(T* ptr)
		:_ptr(ptr),_count(new int(1))
	{}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	myshared_ptr(myshared_ptr& ptr)
		:_ptr(ptr._ptr),_count(ptr._count)
	{
		addref();
	}
	void operator=(myshared_ptr& ptr)
	{
		if (ptr._ptr != _ptr)
		{
			release();
			_ptr = ptr._ptr;
			_count = ptr._count;
			ptr.addref();
		}
	}

	~myshared_ptr()
	{
		release();
	}
private:
	void addref()
	{
		(*_count)++;
	}

	void release()
	{
		*(_count)--;
		if (*(_count) == 0)
		{
			if (_ptr)
			{
				delete _ptr;
				delete _count;
			}
		}
	}
private:
	T* _ptr;
	int* _count;
};
//	    0 
//   1     2 
//3   4  5   6
//    
//6
template<class T>
class mypriority_queue
{
public:
	mypriority_queue(vector<T> &v)
		:_arr(v)
	{
		for (int i = (_arr.size() - 1 - 1) / 2; i >= 0; i--)
		{
			adjust_down(i,_arr.size()-1);
		}
	}

	void sort()
	{
		int end = _arr.size()-1;
		while (end > 0)
		{
			swap(_arr[0], _arr[end]);
			end--;
			adjust_down(0,end);
			
		}
	}
	void push(const T& val)
	{
		_arr.push_back(val);
		adjust_up(_arr.size() - 1);
	}

	void pop()
	{
		std::swap(_arr[0], _arr[_arr.size() - 1]);
		_arr.pop_back();
		adjust_down(0,_arr.size());
	}
	T top()
	{
		return _arr.front();
	}
	
	void adjust_up(int china)
	{
		int parent = (china - 1) / 2;
		while (china > 0)
		{
			if (_arr[parent] > _arr[china])
			{
				swap(_arr[parent], _arr[china]);
			}
			else break;
			china = parent;
			parent = (china - 1) / 2;
		}
	}

	void adjust_down(int parent,int end)
	{
		int china = parent * 2 + 1;
		if (china + 1 < end && _arr[china + 1] < _arr[china])china++;
		while (china <= end)
		{
			if (_arr[china] < _arr[parent])
			{
				swap(_arr[china], _arr[parent]);
			}
			else break;
			parent = china;
			china = parent * 2 + 1;
			if (china + 1 <= end && _arr[china + 1] < _arr[china])china++;
		}
	}
	bool empty()
	{
		return _arr.empty();
	}
	vector<T> _arr;
};


int main()
{
	vector<int> arr = { 2,3,1,5,4,6,9,8,7 };

	mypriority_queue<int> q = arr;
	q.sort();
	for (auto e : q._arr)
	{
		cout << e << " ";
	}


	return 0;
}