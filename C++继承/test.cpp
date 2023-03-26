#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

//class Person
//{
//private://类外不可访问，子类内部也不可以访问。
//	int aaa = 10;
//protected://类外不可访问，子类内部可以访问。
//	int bbb = 10;
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; 
//	int _age = 18;
//};
////继承
//class student :public Person
//{
//public :
//	//继承了Person的name ，和age；
//	student(string S,int num)
//	{
//		_name = S;
//		_age = num;
//		//cout << _name << _age << endl;
//	}
//	void Printstu()
//	{
//		Print();
//		cout << "学生" << " " << _name << ' ' << _age << endl;
//		//子类共有继承了父类，但是对于父类中的私有成员仍是不可访问的
//		//cout << aaa;   //error
//		// 子类共有继承父类，对于保护的成员，可以在子类中访问，但是不可以在类外访问。
//		// 可以看出保护成员限定符是因继承才出现的
//		//cout << bbb;
//	}
//protected:
//	//string _name;//和父类成员变量同名，局部有限，也可以指定访问父类中的
//	//这种现象叫做隐藏
//	//int _age;
//};
//
//
//class son :protected Person
//{
//public:
//	son(string str,int age)
//	{
//		_name = str;
//		_age = age;
//	}
//	void Printson()
//	{
//		Print();
//		cout << bbb;//保护继承可以，子类可以访问父类的保护成员，但是类外不可以访问。
//	}
//};
//int main()
//{
//	Person per;
//	student stu("wq",19);
//	//stu.Print();
//	per.Print();
//	stu.Printstu();
//	//子类共有继承了父类，但是对于父类中的私有成员仍是不可访问的，类外也是不可访问的
//	//cout << stu.aaa;   //eror
//	//son so("xyy",10);
//	//so.Printson();
//	//so.Printson();
//	
//	return 0;
//}

//// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; 
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
//void Test()
//{
//	Student s1;
//	s1.Print();
//};
//
//int mian()
//{
//	Test();
//}

//int main()
//{
//	int n;int k;
//	cin >> n >> k;
//	priority_queue<int,vector<int>,greater<int>> pqe;
//	int arr[30001] = { 0 };
//	for (int i = 0; i < n; i++)
//	{
//		int a;
//		cin >> a;
//		arr[a]++;
//	}
//	for (int i = 0; i < 30001; i++)
//	{
//		if (arr[i])
//		{
//			pqe.push(i);
//		}
//	}
//	if (k > pqe.size())
//	{
//		printf("NO RESULT\n");
//		return 0;
//	}
//	int count =k-1;
//	while (count--)
//	{	
//		pqe.pop();
//	}
//	cout << pqe.top();
//
//	return 0;
//}


class Student;
class Person
{
public:
	
	//友缘
	friend void func(const Person& P, const Student& S);

	//静态成员
	static int count ;
	Person(string name, string sex, int age)
		:_name(name),
		_sex(sex),
		_age(age)
	{
		cout << "Person(string name, string sex, int age)" << endl;
		count++;
	}
	Person(const Person& P)
		:_name( P._name),
		_sex( P._sex),
		_age( P._age)
	{
		cout << "Person(const Person & P)" << endl;
		count++;
	}
	Person& operator=(const Person & P)
	{
		if (this != &P)
		{
			_name = P._name;
			_age = P._age;
			_sex = P._sex;
		}
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
	void pp()
	{
		cout << "name: " << _name << endl;
		cout << "sex: " << _sex << endl;
		cout << "age: " << _age << endl;
	}

protected:
	string _name; 
	string _sex; 
	int _age; 
};
int Person::count = 0;
class Student : public Person
{
public:
	//友缘
	//friend void func(const Person& P, const Student& S);
	Student(string name, string sex, int age, int no)
		//派生类的构造函数必须调用基类的构造函数初始化基类的那一部分成员。如果基类没有默认
		//的构造函数，则必须在派生类构造函数的初始化列表阶段显示调用。
		:Person(name, sex, age),
		_No(no)
	{
		cout << "Student(string name, string sex, int age, int no)" << endl;
	}
	void p()
	{
		cout << "name: " << _name << endl;
		cout << "sex: " << _sex << endl;
		cout << "age: " << _age << endl;
		cout << "no: " << _No << endl;
	}
	Student& operator=(const Student& stu)
	{
		if (&stu != this)
		{
			//派生类的拷贝构造函数必须调用基类的拷贝构造完成基类的拷贝初始化。
			Person::operator=(stu);
			_No = stu._No;
		}
		return *this;
	}
	//派生类的析构函数会在被调用完成后自动调用基类的析构函数清理基类成员。因为这样才能
	//保证派生类对象先清理派生类成员再清理基类成员的顺序。
	~Student()
	{
		cout << "~Student()" << endl;
	}
	int _No; 
};

void func( const Person& P,  const Student& S)
{
	cout << "friend void func()" << P._name <<' ' << S._name << endl;
}

int main()
{
	Person P("www", "0", 16);
	Student S("ppp","1",18,1);
	//S.p();
	//切片，可以将子类赋值给父类。
	//Person pp = S;
	//Student stu1 = S;
	func(P,S);
	//S.func();
	//stu1.p();
	//pp.pp();

	//Person PP(P);
	cout << "______________________________________________________________________________"<<endl;
	cout << Person::count << endl;

	return 0;
}