
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
//	//��ʾʵ����
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


//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	Add<int>(1, 2); // ���ñ������ػ���Add�汾
//}
// 



//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//
//int main()
//{
//	Add(1, 2);		// ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0);    // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
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
	//�洢����Ϊint��ջ
	Stack<int> st1;
	//�洢����Ϊstring��ջ
	Stack<string> st2;
	//�洢����Ϊdouble��ջ
	Stack<double> st3;
	
	return 0;

}
