#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//class Person{
//public:
//	 virtual void  buy_ticket(){cout << "全价票" << endl;}
//};
//
//class Student :public Person{
//public:
//	 virtual void buy_ticket(){cout << "八折票" << endl;}
//};

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	//virtual void BuyTicket() { cout << "买票-半价" << endl; }
//	void BuyTicket() { cout << "买票-半价" << endl; }
//};

//class Person {
//public:
//	virtual Person* BuyTicket() { cout << "买票-全价" << endl; return nullptr; }
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	//virtual void BuyTicket() { cout << "买票-半价" << endl; }
//	virtual Student* BuyTicket() { cout << "买票-半价" << endl; return nullptr; }
//	~Student() { cout << "~Student()" << endl; }
//};

//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};

//class Car {
//public:
//	 void Drive() {}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};

//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-柴油机" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-高能锂电池" << endl;
//	}
//};
//void Test()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}

// 这里常考一道笔试题：sizeof(Base)是多少？
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};


//void Func(Person* p)
//{
//	p->BuyTicket();
//}
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person p;
//	Student s;
//	
//	Person person1 = p;
//	Person person2 = s;
//	
//	person1.buy_ticket();
//	person2.buy_ticket();
//	return 0;
//}



//class Base
//{
//public:
//	virtual void Func1(){cout << "Base::Func1()" << endl;}
//	virtual void Func2(){cout << "Base::Func2()" << endl;}
//	virtual void Func3(){cout << "Base::Func3()" << endl;}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1(){cout << "Derive::Func1()" << endl;}
//	virtual void Func2() { cout << "Derive::Func2()" << endl; }
//	virtual void Func4(){cout << "Derive::Func4()" << endl;}
//private:
//	int _d = 2;
//};
//typedef void (*VFunc)();
//void Print_VFTable(VFunc table[])
//{
//	int i = 0;
//	//虚函数表本质是一个存虚函数指针的指针数组，
//	//一般情况这个数组最后面放了一个nullptr（仅仅针对VS系类编译器）。
//	while (table[i])
//	{
//		printf("[%d]:%p--->", i+1, table[i]);
//		table[i]();
//		i++;
//	}
//}
//int main()
//{
//	Base b;
//	Derive d;
//	Print_VFTable((VFunc*)(*((int*)(&d))));
//	cout << endl;
//	Print_VFTable((VFunc*)(*((int*)(&b))));
//	
//	return 0;
//}

class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
		int b2;
};
class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};
typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	Derive d;
	Base1* b1 = &d;
	Base2* b2 = &d;
	b1->func1();
	b2->func1();
	
	return 0;
}
