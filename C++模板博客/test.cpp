
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;



//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}
//template<typename T>
//void Add(T left, T right)
//{
//	left + right;
//}

//int main()
//{
//	int a = 10;
//	double d1 = 12.2;
//	//Add((double)a, d1);
//	Add<int>(a, d1);
//
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	double d1 = 12.2;
//	//显示实例化
//	Add<int>(a, d1);
//
//	return 0;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//
//	char c1 = 'A';
//	char c2 = 'B';
//	Swap(c1, c2);
//
//	double d1 = 10.2;
//	double d2 = 12.2;
//	Swap(d1, d2);
//
//	return 0;
//}


//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 2); // 调用编译器特化的Add版本
//}
// 



//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//
//int main()
//{
//	Add(1, 2);		// 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0);    // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//	return 0;
//}


//int fun()
//{
//	return 0;
//}
//class Stack
//{
//public:
//	typedef int TYPE;
//	Stack()
//		:_st(new int[10]),_size(0),_cap(10)
//	{
//	}
//
//	void push(int num)
//	{
//		//...
//	}
//	void pop()
//	{
//		//...
//	}
//
//	int size()
//	{
//		return _size;
//	}
//
//	~Stack()
//	{
//		delete[] _st;
//		_size = _cap = 0;
//	}
//private:
//	TYPE *_st;
//	int _size;
//	int _cap;
//};
template<class T>
class Stack
{
public:
	Stack()
		:_st(new int[10]), _size(0), _cap(10)
	{
	}

	void push(int num)
	{
		//...
	}
	void pop()
	{
		//...
	}

	int size()
	{
		return _size;
	}

	~Stack()
	{
		delete[] _st;
		_size = _cap = 0;
	}
private:
	T * _st;
	int _size;
	int _cap;
};

int main()
{
	//存储类型为int的栈
	Stack<int> st1;
	//存储类型为string的栈
	Stack<string> st2;
	//存储类型为double的栈
	Stack<double> st3;
	
	return 0;

}
