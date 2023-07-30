
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

template<class T>
void fun(T a)
{

}
void Test()
{
    // 动态申请一个int类型的空间
    int* ptr4 = new int;
    *ptr4 = 100;
    cout <<"ptr4->" <<* ptr4 << endl;
    // 动态申请一个int类型的空间并初始化为10
    int* ptr5 = new int(10);
    cout << "ptr5->" << *ptr5 << endl;
    // 动态申请3个int类型的空间
    int* ptr6 = new int[3];
    ptr6[0] = 0; ptr6[1] = 1; ptr6[2] = 2;
    cout << "ptr6->" << ptr6[0] <<" "<< ptr6[1] << " " << ptr6[2] << endl;

    delete ptr4;
    delete ptr5;
    delete[] ptr6;
}
int main()
{
    
    Test();
    return 0;
}
//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};

//A* p1 = (A*)malloc(sizeof(A));
//A* p2 = new A(1);
//free(p1);
//delete p2;

//// 内置类型是几乎是一样的
//int* p3 = (int*)malloc(sizeof(int)); // C
//int* p4 = new int;
//free(p3);
//delete p4;



//int main()
//{
//
//	A* p5 = (A*)malloc(sizeof(A) * 10);
//	A* p6 = new A[10];
//	free(p5);
//	delete[] p6;
//	return 0;
//}



//int main()
//{
//
//   
//
//	return 0;
//}

//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:
//	int _a;
//};
//
//// 定位new/replacement new
//int main()
//{
//	// p1现在指向的只不过是与A对象相同大小的一段空间，还不能算是一个对象，因为构造函数有执行
//	A* p1 = (A*)malloc(sizeof(A));
//	new(p1)A;  // 注意：如果A类的构造函数有参数时，此处需要传参
//	p1->~A();
//	free(p1);
//	A* p2 = (A*)operator new(sizeof(A));
//	new(p2)A(10);
//	p2->~A();
//	operator delete(p2);
//	return 0;
//}