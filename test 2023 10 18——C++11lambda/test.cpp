#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void Print(vector<int>& arr)
{
	for (auto e : arr)
	{
		cout << e << " ";
	}
	cout << endl;
}

//int main()
//{
//	vector<int> arr = { 4,1,8,5,3,7,0,9,2,6 };
//
//	//����
//	sort(arr.begin(), arr.end(),greater<int>());
//	Print(arr);
//	//����
//	sort(arr.begin(), arr.end());
//	Print(arr);
//
//	return 0;
//}


//struct Goods
//{
//	string _name;  //����
//	double _price; //�۸�
//	int _evaluate; //����
//	Goods(const char* str, double price, int evaluate)
//		:_name(str)
//		, _price(price)
//		, _evaluate(evaluate)
//	{}
//};
//
//void Print(vector<Goods>& v)
//{
//	for (auto e : v)
//	{
//		cout << e._name << ":" << e._price << ":" << e._evaluate << endl;
//	}
//	cout << endl;
//}
//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 }, { "����", 2.2,3 }, { "����", 1.5, 4 } };
//	sort(v.begin(), v.end(), [](const Goods g1, const Goods g2)->bool {return g1._price < g2._price; });
//	Print(v);
//	sort(v.begin(), v.end(), [](const Goods g1, const Goods g2)->bool {return g1._price > g2._price; });
//	Print(v);
//	return 0;
//}

//int main()
//{
//	int a = 100;
//	int b = 200;
//	int sum = 0;
//	auto lam = [](int a,int b)->int {return a + b; };
//	sum = lam(a,b);
//	cout << "a + b = "<<sum << endl;
//	return 0;
//}\


//int main()
//{
//	int a = 100;
//	int b = 200;
//	int sum = 0;
//	auto lam = [a,b]()mutable
//	{
//		a = b = 50;
//		cout << "a:" << a << endl;
//		cout << "b:" << b << endl;
//	};
//	lam();
//	cout << "a:" << a << endl;
//	cout << "b:" << b << endl;
//	
//	return 0;
//}
//int main()
//{
//	int a = 100;
//	int b = 200;
//	int sum = 0;
//	auto lam1 = [&]()
//	{
//		a = b = 50;
//	};
//	lam1();
//	cout << "a:" << a << endl;
//	cout << "b:" << b << endl;
//	
//	return 0;
//}


//class Test
//{
//public:
//	Test(int a)
//		:_a(a)
//	{
//	}
//
//	void operator()()
//	{
//		//��׽thisָ��֮������ʹ��this��ָ����Ա������ֱ�ӷ������Ա
//		auto Prin_a = [this]() {cout <<"class Teat::_a:" << _a << endl; };
//		Prin_a();
//	}
//
//private:
//	int _a;
//	
//};
//
//int main()
//{
//	Test T(100);
//	T();
//	return 0;
//}
//
//

//class Rate
//{
//public:
//	Rate(double rate) : _rate(rate)
//	{}
//	double operator()(double money, int year)
//	{
//		return money * _rate * year;
//	}
//private:
//	double _rate;
//};
//int main()
//{
//	// ��������
//	double rate = 0.49;
//	Rate r1(rate);
//	r1(10000, 2);
//	// lamber
//	auto r2 = [=](double monty, int year)->double {return monty * rate * year;
//	};
//	r2(10000, 2);
//	return 0;
//}


//
#include<functional>
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
//
//int main()
//{
//	function<double(double)> func1 = f;
//	function<double(double)> func2 = Functor();
//	function<double(double)> func3 = [](double d) {return d / 1; };
//	
//	useF<function<double(double)>, double>(func1, 11.11);
//	useF<function<double(double)>, double>(func2, 11.11);
//	useF<function<double(double)>, double>(func3, 11.11);
//
//	return 0;
//}


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
//	//��װ�Ǿ�̬��Ա����,�ö��󹹽�
//	function<int(Add, int)> fun1 = &Add::add;
//	cout << fun1(Add(10), 30) << endl;
//	
//	//��װ�Ǿ�̬��Ա�������ö���ָ�빹��
//	Add add(10);
//	function<int(Add*, int)> fun3 = &Add::add;
//	cout << fun3(&add, 30) << endl;
//
//	//��װ��̬��Ա����
//	function<int(int,int)> fun2 = Add::s_add;
//	cout << fun2(10, 30) << endl;
//
//	return 0;
//}

//void Plus(int a, int b)
//{
//	cout << a << " " << b << endl;
//}
//
//int main()
//{
//	//��ʾ�󶨺���plus �����ֱ��ɵ��� func1 �ĵ�һ����������ָ��
//	function<void(int, int)> func1 = std::bind(Plus, placeholders::_1, placeholders::_2);
//	func1(1, 2);
//	
//	//ͨ��_2,_1����Ĳ�����λ��
//	function<void(int, int)> func2 = std::bind(Plus, placeholders::_2, placeholders::_1);
//	func2(1, 2);
//
//	return 0;
//}


 class Add
{
public:
	Add(int c)
		:_c(c)
	{}
	int add(int a,int b)
	{
		return (a + b) * _c;
	}
private:
	int _c;
};

int main()
{
	//��װ�Ǿ�̬��Ա����,�ö��󹹽�
	function<int(Add, int,int)> fun1 = &Add::add;
	cout << fun1(Add(10), 3,2) << endl;

	//��װ�Ǿ�̬��Ա����,�ö��󹹽�
	//ָ��һ������Add(10)��Ϊ������ʣ�������������
	function<int(int,int)> fun2 = bind(&Add::add, Add(10), placeholders::_1, placeholders::_2);
	cout << fun2(3,2) << endl;
	
	return 0;
}

