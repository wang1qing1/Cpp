#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//namespace ikun
//{
//
//	//// ����һ��ģ�����͵ľ�̬����
//	//template<class T>
//	//class array
//	//{
//	//public:
//	//	#define N 10
//	//	T& operator[](size_t index) { return _array[index]; }
//	//	const T& operator[](size_t index)const { return _array[index]; }
//	//	size_t size()const { return _size; }
//	//	bool empty()const { return 0 == _size; }
//	//private:
//	//	T _array[N];
//	//	size_t _size;
//	//};
//	
//	// ����һ��ģ�����͵ľ�̬����
//		template<class T, size_t N = 10>
//		class array
//		{
//		public:
//			T& operator[](size_t index) { return _array[index]; }
//			const T& operator[](size_t index)const { return _array[index]; }
//			size_t size()const { return _size; }
//			bool empty()const { return 0 == _size; }
//		private:
//			T _array[N];
//			size_t _size;
//		};
//}

//class Date
//{
//public:
//	Date(int year = 0, int month = 0, int day = 0)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	bool operator<(const Date& date) const 
//	{
//		if (_year != date._year) { return _year < date._year; }
//		if (_month != date._month) { return _month < date._month; }
//		if (_day != date._day) { return _day < date._day; }
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//// ����ģ�� -- ����ƥ��
//template<class T>
//bool Less( T left, T right)
//{
//	return left < right;
//}
//
//// ��Less����ģ������ػ�,�ػ���ר�Ŵ���Date*���͵ıȽ�
//template<>
//bool Less<Date*>( Date* left,  Date* right)
//{
//	cout << "bool Less<Date*>( Date* left,  Date* right)" << endl;
//	return *left < *right;
//}
//
////ֱ�Ӹ�������ʵ�ֵĺ���
//bool Less(Date* left, Date* right)
//{
//	cout << "bool Less(Date* left, Date* right)" << endl;
//	return *left < *right;
//}

//int main()
//{
//	//cout << Less(1, 2) << endl; // ���ԱȽϣ������ȷ
//	Date d1(2022, 7, 9);
//	Date d2(2022, 7, 8);
//	//cout << Less(d1, d2) << endl; // ���ԱȽϣ������ȷ
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl; // ���ԱȽϣ����Ҳ��ȷ
//	return 0;
//}


////��ģ�� -- ������ģ��
//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
////��ģ��---ȫ�ػ�
//template<>
//class Data<int, char>
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//private:
//	int _d1;
//	char _d2;
//};
//
//// ���ڶ��������ػ�Ϊint
//template <class T1>
//class Data<T1, int>
//{
//public:
//	Data() { cout << "Data<T1, int>" << endl; }
//private:
//	T1 _d1;
//	int _d2;
//};
//
////��������ƫ�ػ�Ϊָ������
//template <typename T1, typename T2>
//class Data <T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//private:
//	T1* _d1;
//	T2* _d2;
//};
////��������ƫ�ػ�Ϊ��������
//template <typename T1, typename T2>
//class Data < T1&,  T2&>
//{
//public:
//	Data(const T1& d1, const T2& d2)
//		: _d1(d1)
//		, _d2(d2)
//	{
//		cout << "Data<T1&, T2&>" << endl;
//	}
//private:
//	const T1& _d1;
//	const T2& _d2;
//};
//void test2()
//{
//	Data<double, int> d1; // �����ػ���int�汾
//	Data<int, double> d2; // ���û�����ģ��
//	Data<int*, int*> d3; // �����ػ���ָ��汾
//	Data<int&, int&> d4(int(1), int(2)); // �����ػ������ð汾
//}
//

class A {
public:
	A(float* f)
		:b(1),c( f )
	{
	}

private:

	int a;

public:
	const int b;
	float*& c;
	static const char* d;
	static double* e;
};

template<class T>
struct Add
{

	int sum(int a, int b)
	{
		return a + b;
	}
	int _a;
};

int main()
{

	Add<int> add;
	cout<<add.sum(10, 20);
	//test2();



	return 0;
}



////main.cpp
//#include"TEST.h"
//int main()
//{
//	Add(1, 2);
//	Add(1.0, 2.0);
//	return 0;
//}



