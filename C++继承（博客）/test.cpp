#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

////personl��
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // ����
//	int _age = 18;          // ����
//};
//
////Student�̳�Person
//class Student : public Person
//{
//protected:
//	int _stuid; // ѧ��
//};
//
////Teacher�̳�Person
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����
//};

//// ʵ����ʾ���ּ̳й�ϵ�»����Ա�ĸ����ͳ�Ա���ʹ�ϵ�ı仯 
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name="lili"; // ����
//private:
//	int _age; // ����
//};
//class Student : protected Person
////class Student : private Person
////class Student : public Person
//{
//public:
//	void stu_pri()
//	{
//		Print();
//	}
//protected:
//	int _stunum; // ѧ��
//};
//class Person
//{
//protected:
//	string _name; // ����
//	string _sex;  // �Ա�
//	int _age; // ����
//};
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//
//int main()
//{
//	Student sobj;
//	// 1.���������Ը�ֵ���������/ָ��/����
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//
//	//2.��������ܸ�ֵ�����������
//	sobj = pobj;
//
//	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//	pp = &sobj;
//	Student * ps1 = (Student*)pp; // �������ת��ʱ���Եġ�
//	ps1->_No = 10;
//
//	pp = &pobj;
//	Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
//	ps2->_No = 10;
//
//	return 0;
//}
//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111;          // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
//};

// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
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
//	//��ֵ���������
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
//
//	int _aa;
//};
//class B : public A
//{
//public:
//	//A��û��Ĭ�Ϲ��캯����B�ͱ�����ʾ����A�Ĺ��캯��
//	B()
//		:A(1)
//	{
//	}
//	B(const B& b)
//		:A(b)//���࿽������,����������ǲ���
//	{
//		_bb = b._bb;//������ĵ�������
//	}
//
//	B& operator=(const B& b)
//	{
//		if (&b != this)
//		{
//			A::operator=(b);//���û���ĸ�ֵ�������������ɼ̳в��ֵĸ�ֵ��
//			_bb = b._bb;//�������Լ��ĵ�����ֵ��
//		}
//		return *this;
//	}
//
//	~B()
//	{
//		//A::~A();
//		
//		cout << "~B()" << endl;
//	}
//	int _bb;
//};

//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A
//{
//public:
//	//������Ĺ��캯��������û���Ĺ��캯����ʼ���������һ���ֳ�Ա��
//	//�������Ĭ�Ϲ��캯�����û����Ĭ�Ϲ��졣
//	void fun(int i)
//	{
//		A::fun();
//		cout << "func(int i)->" << i << endl;
//	}
//};

//int main()
//{
//	B b;
//	return 0;
//}

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;//��Person����Ԫ��ϵ�����Է��ʡ�
//	cout << s._stuNum << endl;//��Student������Ԫ��ϵ�������Է��ʡ�
//}
//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//class Graduate : public Student
//{
//protected:
//string _seminarCourse; // �о���Ŀ
//};

//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " ���� :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " ���� :" << Person::_count << endl;
//}

//class Vegetable
//{
//public:
//	Vegetable()
//		:vage_benefit("һ���ܺóԵ��߲�")
//	{
//	}
//	void get_vage_benefit()
//	{
//		cout << vage_benefit << endl;
//	}
//protected:
//	string vage_benefit; 
//};
//
//class Fruit
//{
//public:
//	Fruit()
//		:fruit__benefit("һ���ܺóԵ�ˮ��")
//	{
//	}
//	void get_fruit__benefit()
//	{
//		cout << fruit__benefit << endl;
//	}
//
//protected:
//	string fruit__benefit; 
//};
//
//class Tomato :public Vegetable, public Fruit
//{
//public:
//	Tomato()
//		:tomato_benefit("�������Ⱥó��ֱ���")
//	{
//	}
//	void get_tomato__benefit()
//	{
//		cout << tomato_benefit << endl;
//	}
//
//protected:
//	string tomato_benefit;
//};
//class Person
//{
//public:
//	string _name; // ����
//};
//class Student : public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//class Person
//{
//public:
//	string _name; // ����
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // ְ�����
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//
//void Test()
//{
//	
//	Assistant a;
//	//�����ڶ�������
//	a._name = "peter";
//	
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}
class A
{
public:
	int _a;
};
// class B : public A
class B : virtual public A
{
public:
	int _b;
};
// class C : public A
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};
int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}

