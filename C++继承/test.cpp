#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

//class Person
//{
//private://���ⲻ�ɷ��ʣ������ڲ�Ҳ�����Է��ʡ�
//	int aaa = 10;
//protected://���ⲻ�ɷ��ʣ������ڲ����Է��ʡ�
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
////�̳�
//class student :public Person
//{
//public :
//	//�̳���Person��name ����age��
//	student(string S,int num)
//	{
//		_name = S;
//		_age = num;
//		//cout << _name << _age << endl;
//	}
//	void Printstu()
//	{
//		Print();
//		cout << "ѧ��" << " " << _name << ' ' << _age << endl;
//		//���๲�м̳��˸��࣬���Ƕ��ڸ����е�˽�г�Ա���ǲ��ɷ��ʵ�
//		//cout << aaa;   //error
//		// ���๲�м̳и��࣬���ڱ����ĳ�Ա�������������з��ʣ����ǲ�������������ʡ�
//		// ���Կ���������Ա�޶�������̳вų��ֵ�
//		//cout << bbb;
//	}
//protected:
//	//string _name;//�͸����Ա����ͬ�����ֲ����ޣ�Ҳ����ָ�����ʸ����е�
//	//���������������
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
//		cout << bbb;//�����̳п��ԣ�������Է��ʸ���ı�����Ա���������ⲻ���Է��ʡ�
//	}
//};
//int main()
//{
//	Person per;
//	student stu("wq",19);
//	//stu.Print();
//	per.Print();
//	stu.Printstu();
//	//���๲�м̳��˸��࣬���Ƕ��ڸ����е�˽�г�Ա���ǲ��ɷ��ʵģ�����Ҳ�ǲ��ɷ��ʵ�
//	//cout << stu.aaa;   //eror
//	//son so("xyy",10);
//	//so.Printson();
//	//so.Printson();
//	
//	return 0;
//}

//// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
//class Person
//{
//protected:
//	string _name = "С����"; // ����
//	int _num = 111; 
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
	
	//��Ե
	friend void func(const Person& P, const Student& S);

	//��̬��Ա
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
	//��Ե
	//friend void func(const Person& P, const Student& S);
	Student(string name, string sex, int age, int no)
		//������Ĺ��캯��������û���Ĺ��캯����ʼ���������һ���ֳ�Ա���������û��Ĭ��
		//�Ĺ��캯����������������๹�캯���ĳ�ʼ���б�׶���ʾ���á�
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
			//������Ŀ������캯��������û���Ŀ���������ɻ���Ŀ�����ʼ����
			Person::operator=(stu);
			_No = stu._No;
		}
		return *this;
	}
	//������������������ڱ�������ɺ��Զ����û��������������������Ա����Ϊ��������
	//��֤����������������������Ա����������Ա��˳��
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
	//��Ƭ�����Խ����ำֵ�����ࡣ
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