#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//class Person{
//public:
//	 virtual void  buy_ticket(){cout << "ȫ��Ʊ" << endl;}
//};
//
//class Student :public Person{
//public:
//	 virtual void buy_ticket(){cout << "����Ʊ" << endl;}
//};

//class Person {
//public:
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//class Student : public Person {
//public:
//	//virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//	void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};

//class Person {
//public:
//	virtual Person* BuyTicket() { cout << "��Ʊ-ȫ��" << endl; return nullptr; }
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	//virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//	virtual Student* BuyTicket() { cout << "��Ʊ-���" << endl; return nullptr; }
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
//	virtual void Drive() { cout << "Benz-����" << endl; }
//};

//class Car {
//public:
//	 void Drive() {}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-����" << endl; }
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
//		cout << "Benz-���ͻ�" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-����﮵��" << endl;
//	}
//};
//void Test()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}

// ���ﳣ��һ�������⣺sizeof(Base)�Ƕ��٣�
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
//	//�麯��������һ�����麯��ָ���ָ�����飬
//	//һ��������������������һ��nullptr���������VSϵ�����������
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
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
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
