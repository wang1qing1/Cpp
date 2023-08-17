#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

////personl类
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//	int _age = 18;          // 年龄
//};
//
////Student继承Person
//class Student : public Person
//{
//protected:
//	int _stuid; // 学号
//};
//
////Teacher继承Person
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号
//};

//// 实例演示三种继承关系下基类成员的各类型成员访问关系的变化 
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name="lili"; // 姓名
//private:
//	int _age; // 年龄
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
//	int _stunum; // 学号
//};
//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex;  // 性别
//	int _age; // 年龄
//};
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//int main()
//{
//	Student sobj;
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//
//	//2.基类对象不能赋值给派生类对象
//	sobj = pobj;
//
//	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
//	pp = &sobj;
//	Student * ps1 = (Student*)pp; // 这种情况转换时可以的。
//	ps1->_No = 10;
//
//	pp = &pobj;
//	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//	ps2->_No = 10;
//
//	return 0;
//}
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111;          // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};

// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
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
//
//	int _aa;
//};
//class B : public A
//{
//public:
//	//A中没有默认构造函数，B就必须显示调用A的构造函数
//	B()
//		:A(1)
//	{
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
//	//派生类的构造函数必须调用基类的构造函数初始化基类的那一部分成员。
//	//派生类的默认构造函数调用基类的默认构造。
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
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;//与Person是友元关系，可以访问。
//	cout << s._stuNum << endl;//与Student不是友元关系，不可以访问。
//}
//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//class Graduate : public Student
//{
//protected:
//string _seminarCourse; // 研究科目
//};

//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " 人数 :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " 人数 :" << Person::_count << endl;
//}

//class Vegetable
//{
//public:
//	Vegetable()
//		:vage_benefit("一个很好吃的蔬菜")
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
//		:fruit__benefit("一个很好吃的水果")
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
//		:tomato_benefit("西红柿既好吃又便宜")
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
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//void Test()
//{
//	
//	Assistant a;
//	//不存在二义性了
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

