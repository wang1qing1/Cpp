#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//1. ����ͨ�������ָ��������õ����麯��
//2. �����õĺ����������麯���������������Ի�����麯��������д
//class Person
//{
//public:
//	//�麯��
//	virtual void show()
//	{
//		cout << "class Person" << endl;
//	}
//};
//class Student : public Person
//{
//public:
//	//�麯������д(����)
//	virtual void show()
//	{
//		cout << "class Student" << endl;
//	}
//	/*ע�⣺����д�����麯��ʱ����������麯���ڲ���virtual�ؼ���ʱ����ȻҲ���Թ�����д(��
//	Ϊ�̳к������麯�����̳������������������ɱ����麯������),���Ǹ���д�����Ǻܹ淶��������
//	����ʹ��*/
//	/*void show()
//	{
//		cout << "class Student" << endl;
//	}*/
//	
//};
//int main()
//{
//	Person* Ps = new Student;
//	Person* Pp = new Person;
//	//��̬
//	Ps->show();
//	Pp->show();
//	return 0;
//}


////һ������£���д�麯����ʱ�򣬱���Ҫ�������жԸ������麯������д���룬��ͬ��������������������������
////������һ�����⣺��������麯���ķ���ֵ�Ǹ�������û�ָ�룬������д���麯���ķ���ֵ����������û�ָ��ʱ
////��ʹ����ֻ��ͬ������Ҳ�ǿ���ʵ����д�ġ����ǳ��������������Э�䣡����
//class Person
//{
//public:
//	//�麯��
//	virtual Person& show()
//	{
//		cout << "class Person" << endl;
//		return *this;
//	}
//};
//
//class Student : public Person
//{
//public:
//	//�麯������д(����)
//	virtual Student& show()
//	{
//		cout << "class Student" << endl;
//		return *this;
//
//	}
//};
//int main()
//{
//	Person* Ps = new Student;
//	Person* Pp = new Person;
//	//��̬
//	Ps->show();
//	Pp->show();
//	return 0;
//}
//


//������������д����
//����������������Ϊ�麯������ʱ��������������ֻҪ���壬�����Ƿ��virtual�ؼ��֣�
//����������������������д����Ȼ�����������������������ֲ�ͬ����Ȼ����������ͬ��
//������Υ������д�Ĺ�����ʵ��Ȼ������������Ϊ�����������������������������⴦
//���������������������ͳһ�����destructor��
//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//// ֻ��������Student������������д��Person�����������������delete�������������
//// �������ܹ��ɶ�̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	
//	//���ɶ�̬��
//	delete p1;
//	delete p2;
//	return 0;
//}

//class Person {
//public:
//		~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//		~Student()
//		{ 
//			//��������಻��virtual����ʹ��������ͬ�Իṹ�����ع�ϵ����Ϊ�������������������������ͳһ����
//			//����̳и��࣬����ԭ���ڸ�����еĳ�Ա����Ȼʱ���ã�����������������������ø��������������
//			//�������ڵ������Լ������������Զ����õ�
//			Person::~Person();
//			cout << "~Student()" << endl;
//		}
//};
//// ֻ��������Student������������д��Person�����������������delete�������������
//// �������ܹ��ɶ�̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������
//int main()
//{
//	Person* p1 = new Person;
//	Student* p2 = new Student;
//
//	//���ɶ�̬��
//	delete p1;
//	delete p2;
//	return 0;
//}

//�����࣡��
// ���������Ϊ���麯�����������麯��������������ࣨҲ�нӿ�
//�ࣩ�������಻��ʵ����������������̳к�Ҳ����ʵ����������ֻ����д���麯��������
//�����ʵ���������󡣴��麯���淶�������������д�����ⴿ�麯�������ֳ��˽ӿڼ̳С�
//class Car
//{
//public:
// //������
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-����" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-�ٿ�" << endl;
//	}
//};
//void Test()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}
//
////��������:��������ͬ��������ͬ�������ķ���ֵ��ͬ�����ܹ��ɺ�������
//
//int main()
//{
//	Test();
//}
// 

//�ӿڼ̳к�ʵ�ּ̳�!!
//��ͨ�����ļ̳���һ��ʵ�ּ̳У�������̳��˻��ຯ��������ʹ�ú������̳е��Ǻ�����ʵ
//�֡��麯���ļ̳���һ�ֽӿڼ̳У�������̳е��ǻ����麯���Ľӿڣ�Ŀ����Ϊ����д�����
//��̬���̳е��ǽӿڡ����������ʵ�ֶ�̬����Ҫ�Ѻ���������麯��

//class Car
//{
//public:
//	virtual void Drive(string str = "class Car")
//	{
//		cout << str << endl;
//	}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive(string str="class Benz :public Car")
//	{
//		cout << "Benz-���� "<< str  << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive(string str)
//	{
//		cout << "BMW-�ٿ�" << str << endl;
//	}
//};
//
//int main()
//{
//
//	Car car;
//	Car* ben = new Benz;
//	Car* bmw = new BMW;
//
//	car.Drive("cccccccc");
//	ben->Drive("bbbbbbbb");
//	bmw->Drive();
//
//	//���н����
//
//	//car.Drive("cccccccc");  ---->  cccccccc
//	//ben->Drive();           ---->  Benz-���� class Car  
//	//bmw->Drive();           ---->  BMW-�ٿ�class Car
//	//�����ǽӿڼ̳У�ben��Drive����������̳��˸���Ľӿڣ�����ֻ����д�˺����塣
//	return 0;
//
//}

//���ﳣ��һ�������⣺sizeof(Base)�Ƕ��٣�
//ͨ���۲�������Ƿ���b������8bytes������_b��Ա������һ��__vfptr���ڶ����ǰ��(ע����Щ
//ƽ̨���ܻ�ŵ����������棬�����ƽ̨�й�)�������е����ָ�����ǽ����麯����ָ��(v��
//��virtual��f����function)��һ�������麯�������ж����ٶ���һ���麯����ָ�룬��Ϊ�麯��
//�ĵ�ַҪ���ŵ��麯�����У��麯����Ҳ��������
//class Base
//{
//public:
//	virtual void func1()
//	{
//		cout << "Func1()" << endl;
//		return;
//	}
//private:
//	int _b = 1;
//};
//int main()
//{
//	Base a;
//	cout << sizeof a << endl;
//	//���н����8��˵������Base�в�������_bһ����Ա������һ��ָ�롣
//	return 0;
//}class Base
class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};
class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};
int main()
{
	Base b;
	Derive d;
	d.Func2();
	return 0;
}
