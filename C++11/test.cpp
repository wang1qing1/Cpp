#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
#include<map>

using namespace std;


//struct Point
//{
//	int _x;
//	int _y;
//};
//int main()
//{
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//	Point p = { 1, 2 };
//	return 0;
//}
//struct Point
//{
//	int _x;
//	int _y;
//};
//int main()
//{
//	int x1 = 1;
//	//C++11
//	int x2{ 2 };
//	//C++11
//	int array1[]{ 1, 2, 3, 4, 5 };
//	int array2[5]{ 0 };
//	//C++11
//	Point p{ 1, 2 };
//	// C++11���б��ʼ��Ҳ����������new���ʽ��
//	int* pa = new int[4] { 0 };
//	return 0;
//}

class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int year, int month, int day)" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
//int main()
//{
//	Date d1(2022, 1, 1); // old style
//	// C++11֧�ֵ��б��ʼ�����������ù��캯����ʼ��
//	Date d2{ 2022, 1, 2 };
//	Date d3 = { 2022, 1, 3 };
//	return 0;
//}

//int main()
//{
//	
//	list<int> li = { 10, 20, 30 };
//	
//	return 0;
//}

//int main()
//{
//	int i = 10;
//	auto p = &i;
//	auto pf = strcpy;
//	cout << typeid(p).name() << endl;
//	cout << typeid(pf).name() << endl;
//	map<string, string> dict = { {"sort", "����"}, {"insert", "����"} };
//	
//	auto it = dict.begin();//�ȼ���map<string, string>::iterator it = dict.begin();
//	return 0;
//}

// decltype��һЩʹ��ʹ�ó���
template<class T1, class T2>
void F(T1 t1, T2 t2)
{
	//��t1*t2������������������
	decltype(t1 * t2) ret;
	cout << typeid(ret).name() << endl;
}
int main()
{
	const int x = 1;
	double y = 2.2;
	decltype(x * y) ret; // ret��������double
	decltype(&x) p;		 // p��������int*
	cout << typeid(ret).name() << endl;
	cout << typeid(p).name() << endl;
	F(1, 'a');
	return 0;
}