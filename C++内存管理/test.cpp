
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

template<class T>
void fun(T a)
{

}
void Test()
{
    // ��̬����һ��int���͵Ŀռ�
    int* ptr4 = new int;
    *ptr4 = 100;
    cout <<"ptr4->" <<* ptr4 << endl;
    // ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
    int* ptr5 = new int(10);
    cout << "ptr5->" << *ptr5 << endl;
    // ��̬����3��int���͵Ŀռ�
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

//// ���������Ǽ�����һ����
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
//// ��λnew/replacement new
//int main()
//{
//	// p1����ָ���ֻ��������A������ͬ��С��һ�οռ䣬����������һ��������Ϊ���캯����ִ��
//	A* p1 = (A*)malloc(sizeof(A));
//	new(p1)A;  // ע�⣺���A��Ĺ��캯���в���ʱ���˴���Ҫ����
//	p1->~A();
//	free(p1);
//	A* p2 = (A*)operator new(sizeof(A));
//	new(p2)A(10);
//	p2->~A();
//	operator delete(p2);
//	return 0;
//}