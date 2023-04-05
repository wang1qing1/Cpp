#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//1. 必须通过基类的指针或者引用调用虚函数
//2. 被调用的函数必须是虚函数，且派生类必须对基类的虚函数进行重写
//class Person
//{
//public:
//	//虚函数
//	virtual void show()
//	{
//		cout << "class Person" << endl;
//	}
//};
//class Student : public Person
//{
//public:
//	//虚函数的重写(覆盖)
//	virtual void show()
//	{
//		cout << "class Student" << endl;
//	}
//	/*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因
//	为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议
//	这样使用*/
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
//	//多态
//	Ps->show();
//	Pp->show();
//	return 0;
//}


////一般情况下，重写虚函数的时候，必须要求子类中对父类中虚函数的重写必须，三同——函数名，参数，返回类型
////但是有一个例外：当父类的虚函数的返回值是父类的引用或指针，子类重写的虚函数的返回值是子类的引用或指针时
////即使返回只不同，但是也是可以实现重写的。我们称这种现象叫做：协变！！！
//class Person
//{
//public:
//	//虚函数
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
//	//虚函数的重写(覆盖)
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
//	//多态
//	Ps->show();
//	Pp->show();
//	return 0;
//}
//


//析构函数的重写！！
//如果基类的析构函数为虚函数，此时派生类析构函数只要定义，无论是否加virtual关键字，
//都与基类的析构函数构成重写，虽然基类与派生类析构函数名字不同。虽然函数名不相同，
//看起来违背了重写的规则，其实不然，这里可以理解为编译器对析构函数的名称做了特殊处
//理，编译后析构函数的名称统一处理成destructor。
//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函
//// 数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	
//	//构成多态，
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
//			//父类和子类不加virtual，即使函数明不同仍会构成隐藏关系，因为编译器会对析构函数明，进行统一处理。
//			//子类继承父类，但是原属于父类的中的成员，仍然时调用，父类的析构函数来处理，调用父类的析构函数，
//			//是子类在调用完自己的析构函数自动调用的
//			Person::~Person();
//			cout << "~Student()" << endl;
//		}
//};
//// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函
//// 数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
//int main()
//{
//	Person* p1 = new Person;
//	Student* p2 = new Student;
//
//	//构成多态，
//	delete p1;
//	delete p2;
//	return 0;
//}

//抽象类！！
// 则这个函数为纯虚函数。包含纯虚函数的类叫做抽象类（也叫接口
//类），抽象类不能实例化出对象。派生类继承后也不能实例化出对象，只有重写纯虚函数，派生
//类才能实例化出对象。纯虚函数规范了派生类必须重写，另外纯虚函数更体现出了接口继承。
//class Car
//{
//public:
// //抽象函数
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
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
////函数重载:函数名相同，参数不同，单纯的返回值不同，不能构成函数重载
//
//int main()
//{
//	Test();
//}
// 

//接口继承和实现继承!!
//普通函数的继承是一种实现继承，派生类继承了基类函数，可以使用函数，继承的是函数的实
//现。虚函数的继承是一种接口继承，派生类继承的是基类虚函数的接口，目的是为了重写，达成
//多态，继承的是接口。所以如果不实现多态，不要把函数定义成虚函数

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
//		cout << "Benz-舒适 "<< str  << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive(string str)
//	{
//		cout << "BMW-操控" << str << endl;
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
//	//运行结果：
//
//	//car.Drive("cccccccc");  ---->  cccccccc
//	//ben->Drive();           ---->  Benz-舒适 class Car  
//	//bmw->Drive();           ---->  BMW-操控class Car
//	//由于是接口继承，ben的Drive函数，子类继承了父类的接口，子类只是重写了函数体。
//	return 0;
//
//}

//这里常考一道笔试题：sizeof(Base)是多少？
//通过观察测试我们发现b对象是8bytes，除了_b成员，还多一个__vfptr放在对象的前面(注意有些
//平台可能会放到对象的最后面，这个跟平台有关)，对象中的这个指针我们叫做虚函数表指针(v代
//表virtual，f代表function)。一个含有虚函数的类中都至少都有一个虚函数表指针，因为虚函数
//的地址要被放到虚函数表中，虚函数表也简称虚表，。
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
//	//运行结果是8，说明类中Base中不仅仅有_b一个成员，还有一个指针,这个指针就是虚表指针，是一个
//  //函数指针数组指针，指向一个数组，数组里面存的就是虚函数的指针
//	return 0;
//}class Base

//多态的原理：
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Derive::Func2()" << endl;
//	}
//private:
//	int _d = 2;
//};
//int main()
//{
//	Derive D;
//	Base B;
//	//通过父类的指针调用，由于指向的不同，在调用虚函数时将会在自己指向的那日容中找虚函数表。
//	Base* Dptr = &D;
//	Base* Bptr = &B;
//	Dptr->Func1();
//	Bptr->Func1();
//
//}
//

//class Base{
//public:
//	virtual void Func1(){cout << "Base::Func1()" << endl;}
//	virtual void Func2(){cout << "Base::Func2()" << endl;}
//private:
//	int _b = 1;
//};
//class Derive : public Base{
//public:
//	virtual void Func1(){cout << "Derive::Func1()" << endl;}
//	virtual void Func2(){cout << "Derive::Func2()" << endl;}
//	//当我们在子类中多添加一个，虚函数Fun3，这个虚函数会存在哪里？
//	//在调试监视窗口，里面我们查看d对象的虚表，并没有发现Fun3的函数地址。
//	//其实并不是没有只是，监视窗口给我们做了隐藏。我们可以通过打印虚表来看。
//	virtual void Func3(){cout << "Derive::Func3()" << endl;}
//private:
//	int _d = 2;
//};
//typedef void(*VFtable)();
//void Print_VFtable(VFtable vftable[]){
//	for (int i = 0; vftable[i] != nullptr; i++){
//		printf("VFtable[%d]->%p ", i, vftable[i]);
//		vftable[i]();
//	}
//}
//int main(){
//	Base b;
//	Derive d;
//	Base* Bptr = &b;
//	Base* Dptr = &d;
//	Print_VFtable((VFtable*)(*(int*)&b));
//	cout << endl;
//	Print_VFtable((VFtable*)(*(int*)&d));
//	return 0;
//}

//多继承的虚表特点
//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
////多继承中，子类会继承父类的虚表。
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	//针对于多继承中，子类中的未重写的虚函数，会默认放到第一个继承的
//	//父类的虚表中，并且在监视窗口中也是看不到的。
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[]){
//	cout << " 虚表地址>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i){
//		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//int main(){
//	Derive d;
//	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
//	PrintVTable(vTableb1);
//	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
//	PrintVTable(vTableb2);
//	return 0;
//}

//多继承的虚表特点
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
//多继承中，子类会继承父类的虚表。
class Derive : public Base1, public Base2 {
public:
	//派生类中会重写两个基类中继承的Fun1函数，但是我们发现虚表中，
	//继承两个基类的虚表中，Fun1的地址并不一样。
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};
int main() {
	Derive d;
	/*d.Base1::func1();
	d.Base2::func1();*/
	Base1* b1ptr = &d;
	Base2* b2ptr = &d;
	b1ptr->func1();
	b2ptr->func1();


	return 0;
}
